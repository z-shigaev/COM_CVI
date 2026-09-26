/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2026. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_TEXT_RX                    2
#define  PANEL_TEXT_TX                    3       /* callback function: TEXT_TX_CALLBACK */
#define  PANEL_RING_TX_BAUDRATE           4
#define  PANEL_RING_TX_PARITY             5
#define  PANEL_RING_TX_STOP_BITS          6
#define  PANEL_RING_TX_DATA_LEN           7
#define  PANEL_CMD_COM_OPEN               8       /* callback function: CMD_COM_OPEN_CB */
#define  PANEL_LED_TX                     9
#define  PANEL_COM_TX                     10
#define  PANEL_TIMER                      11      /* callback function: RX_OUT_CB */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CMD_COM_OPEN_CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RX_OUT_CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TEXT_TX_CALLBACK(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
