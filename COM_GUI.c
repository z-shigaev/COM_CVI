//==============================================================================
//
// Title:       COM_GUI
// Purpose:     A short description of the application.
//
// Created on:  22.09.2026 at 23:18:12 by Zam.
// Copyright:   PSU. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <rs232.h>
#include <ansi_c.h>
#include <cvirte.h>     
#include <userint.h>
#include "COM_GUI.h"
#include "toolbox.h"
#include "MY_COM.h"

//==============================================================================
// Constants
#define MAX_VISIBLE_TX_TEXT 4096
#define MAX_VISIBLE_RX_TEXT 4096
#define MAX_TX_BUF 1024
#define MAX_RX_BUF 1024
//==============================================================================
// Types

//==============================================================================
// Static global variables

static int panelHandle;

//==============================================================================
// Static functions

//==============================================================================
// Global variables
type_COM_cfg com_cfg;
char tx_text[MAX_VISIBLE_TX_TEXT];
char tx_buf[MAX_TX_BUF];
char rx_buf[MAX_RX_BUF];
char com_port_name[20];
unsigned char tx_buf_len = 0;
static int last_enter_pos = 0;
static int rx_ptr = 0;

//==============================================================================
// Prototypes
void ComCallback(int portnumber, int event, void *callbackData);

//==============================================================================
// Global functions

void getTxParams(type_COM_cfg *cfg){
	GetCtrlVal(panelHandle, PANEL_RING_TX_BAUDRATE, &cfg->baud);
	GetCtrlVal(panelHandle, PANEL_RING_TX_DATA_LEN, &cfg->data_len);
	GetCtrlVal(panelHandle, PANEL_RING_TX_STOP_BITS, &cfg->stop_bits);
	GetCtrlVal(panelHandle, PANEL_RING_TX_PARITY, &cfg->parity);
	GetCtrlVal(panelHandle, PANEL_COM_TX, &cfg->com_number);
}

/// HIFN The main entry-point function.
int main (int argc, char *argv[])
{
    int error = 0;
	
    
    /* initialize and load resources */
    nullChk (InitCVIRTE (0, argv, 0));
    errChk (panelHandle = LoadPanel (0, "COM_GUI.uir", PANEL));
    
	// code
	//printf("%d\n", sizeof(int));
	
    /* display the panel and run the user interface */
    errChk (DisplayPanel (panelHandle));
    errChk (RunUserInterface ());
	
Error:
    /* clean up */
    DiscardPanel (panelHandle);
    return 0;
}

//==============================================================================
// UI callback function prototypes

/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
        int eventData1, int eventData2)
{
    if (event == EVENT_CLOSE)
        QuitUserInterface (0);
    return 0;
}

int CVICALLBACK CMD_COM_OPEN_CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char open_state = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			getTxParams(&com_cfg);
			sprintf(com_port_name, "COM%d", com_cfg.com_number);
			open_state = OpenComConfig(com_cfg.com_number, com_port_name, com_cfg.baud, com_cfg.parity, com_cfg.data_len, com_cfg.stop_bits, MAX_RX_BUF, MAX_TX_BUF);
			if (open_state >= 0){
				SetCtrlVal(panelHandle, PANEL_LED_TX, 1);
				//
				InstallComCallback(com_cfg.com_number, LWRS_RXCHAR, 0, 0, ComCallback, NULL);
			}
			break;
	}
	return 0;
}

int CVICALLBACK TEXT_TX_CALLBACK (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int text_len = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			break;
		case EVENT_KEYPRESS:
			if (eventData1 == VAL_ENTER_VKEY){
				GetCtrlAttribute(panelHandle, PANEL_TEXT_TX, ATTR_STRING_TEXT_LENGTH, &text_len);
				if (text_len >= sizeof(tx_text)){
					text_len = sizeof(tx_text) - 1;
				}
				GetCtrlVal(panelHandle, PANEL_TEXT_TX, tx_text);
				if (text_len > last_enter_pos){
					sprintf(tx_buf, "%.*s", text_len - last_enter_pos, &tx_text[last_enter_pos]);
					tx_buf_len = text_len - last_enter_pos;
					ComWrt(com_cfg.com_number, tx_buf, tx_buf_len);
				}
				last_enter_pos = text_len+1;
			}
			break;
	}
	return 0;
}

void ComCallback(int portNumber, int event, void *callbackData)
{
	int len = 0;
	if (event & LWRS_RXCHAR)
	{
		{
			len = GetInQLen(portNumber);
			if (len > 0){
				if ((len + rx_ptr) > (MAX_RX_BUF - 1)) {	
					rx_ptr = MAX_RX_BUF - 1;
				}
				ComRd(portNumber, &rx_buf[rx_ptr], len);
				rx_ptr += len;
			}
		}

	}
}
	

int CVICALLBACK RX_OUT_CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			if (rx_ptr != 0){
				char newLine[rx_ptr+2];
				memcpy(newLine, rx_buf, rx_ptr);
				newLine[rx_ptr - 1] = '\n';
				newLine[rx_ptr] = '\0';
				SetCtrlVal(panelHandle, PANEL_TEXT_RX, newLine);
				rx_ptr = 0;
			}
			break;
	}
	return 0;
}
