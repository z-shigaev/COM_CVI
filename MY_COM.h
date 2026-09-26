//==============================================================================
//
// Title:       MY_COM.h
// Purpose:     A short description of the interface.
//
// Created on:  22.09.2026 at 23:44:35 by Zam.
// Copyright:   PSU. All Rights Reserved.
//
//==============================================================================

#ifndef __MY_COM_H__
#define __MY_COM_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types
#pragma pack(push, 2)
		
typedef struct 
{
	int baud;
	unsigned char com_number;	//0-30
	unsigned char data_len;		//5-8
	unsigned char stop_bits;	//0 - 1, 1 - 1.5, 2 - 2
	unsigned char parity;		//0 - N, 1 - O, 2 - E
} type_COM_cfg;

#pragma pack(pop)
		
//==============================================================================
// External variables

//==============================================================================
// Global functions

int Declare_Your_Functions_Here (int x);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __MY_COM_H__ */
