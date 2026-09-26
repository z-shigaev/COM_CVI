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
#define  PANEL_RING_RX_BAUDRATE           4
#define  PANEL_RING_RX_PARITY             5
#define  PANEL_RING_RX_STOP_BITS          6
#define  PANEL_RING_RX_DATA_LEN           7
#define  PANEL_RING_TX_BAUDRATE           8
#define  PANEL_RING_TX_PARITY             9
#define  PANEL_RING_TX_STOP_BITS          10
#define  PANEL_RING_TX_DATA_LEN           11
#define  PANEL_CMD_RX_CONNECT             12      /* callback function: CMD_RX_CALLBACK */
#define  PANEL_CMD_TX_CONNECT             13      /* callback function: CMD_TX_CALLBACK */
#define  PANEL_LED_RX                     14
#define  PANEL_LED_TX                     15
#define  PANEL_CMD                        16
#define  PANEL_COM_RX                     17
#define  PANEL_COM_TX                     18


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CMD_RX_CALLBACK(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CMD_TX_CALLBACK(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TEXT_TX_CALLBACK(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
