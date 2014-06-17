/******************************************************************************
* Name: radio.h
* Desc: Software module for AT86RF231 (SPI)
* Date: 2010-06-02
* Author: stanbaek
******************************************************************************/
#ifndef __RADIO_H
#define __RADIO_H

#define DEFAULT_CHANNEL         0x0014
#define DEFAULT_DEST_PAN_ID     0x0000
#define DEFAULT_SRC_PAN_ID      0x0000

#if defined(__S1)
	#define DEFAULT_SRC_ADDR                0x0011

#elif defined(__S2)
	#define DEFAULT_SRC_ADDR                0x0012
	
#elif defined(__S3)
	#define DEFAULT_SRC_ADDR                0x0013
	
#elif defined(__S4)
	#define DEFAULT_SRC_ADDR                0x0014

#elif defined(__S5)
	#define DEFAULT_SRC_ADDR                0x0015
	
#elif defined(__S6)
	#define DEFAULT_SRC_ADDR                0x0016

#elif defined(__S7)
	#define DEFAULT_SRC_ADDR                0x0017

#elif defined(__S8)
	#define DEFAULT_SRC_ADDR                0x0018

#else
	#define DEFAULT_SRC_ADDR                0x0110

#endif

#if defined(__D0100)
	#define DEFAULT_DEST_ADDR				0x0100

#else
	#define DEFAULT_DEST_ADDR				0x0101

#endif

void radioSetup(void);

/*****************************************************************************
* Function Name : radioReadId
* Description   : This function reads ID number of AT86RF231 chip
* Parameters    : A character array of size 4 to hold id value
* Return Value  : None
*****************************************************************************/

void radioReadTrxId(unsigned char *id);

unsigned char radioGetTrxState(void);

unsigned char radioGetChar(char *data);

unsigned char radioIsRxDataReady(void);

unsigned int radioRxData(char *buffer);

void radioTxData(unsigned char length, char *buffer,
                  unsigned char status, unsigned char type);

#endif // __RADIO_H
