/******************************************************************************
* Name: main.c
* Desc: 
* Date: 2010-07-08
* Author: stanbaek
*******************************************************************************/

#include "p33Fxxxx.h"
#include "init_default.h"
#include "radio_polling.h"
#include "bootloader.h"
#include "utils.h"
#include <xc.h>

#define SRC_ADDR_LOC        0x400

typedef union tuReg32 {
    unsigned long Val32;
    struct {
    unsigned short LW;
    unsigned short HW;
    } Word;
    char Val[4];
} uReg32;

int main(void) {
	
    SetupClock();
    SwitchClocks();
    SetupPorts();

    int i = 0;
    for (i=0; i < 3; i++)
    {
        LED_1 = 1; LED_2 = 1; LED_3 = 1;
        delay_ms(200);
        LED_1 = 0; LED_2 = 0; LED_3 = 0;
        delay_ms(200);
        LED_1 = 1; LED_2 = 1; LED_3 = 1;
        delay_ms(200);
    }

    uReg32 addr;
    addr.Val32 = SRC_ADDR_LOC;

    char src_str[2];
    src_str[0] = DEFAULT_SRC_ADDR;
    src_str[1] = DEFAULT_SRC_ADDR >> 8;

    // src_str[0] = 0x00;
    // src_str[1] = 0x12;

    pmWritePage(src_str,addr.Val32);

    //LED_1 = 0;
    //delay_ms(2000);

    //unsigned int res;

    // unsigned long res = pmReadMem(addr.Val32);
    // if (res == 0x0012){
    //     LED_1=~LED_1;
    //     delay_ms(2000);
    // }

    //TBLPAG = 0x0;
    //unsigned int res = __builtin_tblrdl(0x400);
    
    // res = ReadLatch(0x0000, 0x0400);
    // if (res == 0x12){
    //       LED_1 = ~LED_1;
    //       delay_ms(1000);
    //   }

    radioSetup();   // polling mode
    bootSetup();

    LED_1 = 1; LED_2 = 1; LED_3 = 1;
    delay_ms(500);
    LED_1 = 0; LED_2 = 0; LED_3 = 0;
    delay_ms(200);
    LED_1 = 1; LED_2 = 1; LED_3 = 1;
    delay_ms(500);

    //check if radio is working and at the right state.
    while (radioGetTrxState() != 0x16);

    LED_1 = 0;
    LED_2 = 0;
    LED_3 = 0;
    
    bootTestRadio();
    bootRun();
    bootReset();

    while(1);
    return 1;
}

