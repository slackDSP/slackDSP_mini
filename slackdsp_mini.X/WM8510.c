/*
 *File:   WM8510.c
 *
 *   Copyright © 2015 Ian Maltby
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "WM8510.h"

 //initialise SPI port

void WM8510_init(void) {
    WM8510_SS = 1; //disable WM8510
    SPI1CON1bits.DISSCK = 0; //clock enabled
    SPI1CON1bits.DISSDO = 0; //SDO enabled
    SPI1CON1bits.MODE16 = 1; //16 bit mode
    SPI1CON1bits.SMP = 0; //data sampled in middle
    SPI1CON1bits.CKE = 1; //data changes on falling edge (active to idle)
    SPI1CON1bits.CKP = 0; //idle is low
    SPI1CON1bits.PPRE = 0; //64:1 primary prescaler
    SPI1CON1bits.SPRE = 0; //8:1 secondary prescaler (78.125kHz SPI clock)
    SPI1CON1bits.MSTEN = 1; //master mode
    SPI1STATbits.SPIEN = 1; //enable SPI
}

//spi write

void WM8510_write(int reg, int data) {

    int temp;

    WM8510_SS = 0;

    SPI1BUF = (data | (reg << 9));
    while (!SPI1STATbits.SPIRBF);
    temp = SPI1BUF;
  
    WM8510_SS = 1;
}
