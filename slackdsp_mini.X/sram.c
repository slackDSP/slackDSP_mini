/*
 *File:   sram.c
 *
 *   Copyright © 2015 Ian Maltby
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "sram.h"

void sram_init(int sram_mode) {

    int temp;

    sram_SS = 1; //disable sram
    SPI2CON1bits.DISSCK = 0; //clock enabled
    SPI2CON1bits.DISSDO = 0; //SDO enabled
    SPI2CON1bits.MODE16 = 0; //8 bit mode
    SPI2CON1bits.SMP = 0; //data sampled in middle
    SPI2CON1bits.CKE = 1; //data changes on falling edge (active to idle)
    SPI2CON1bits.CKP = 0; //idle is low
    SPI2CON1bits.PPRE = 2; //4:1 primary prescaler
    SPI2CON1bits.SPRE = 7; //1:1 secondary prescaler (10Mhz SPI clock)
    SPI2CON1bits.MSTEN = 1; //master mode
    SPI2STATbits.SPIEN = 1; //enable SPI

    sram_SS = 0;

    SPI2BUF = wrsr;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sram_mode;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    sram_SS = 1;
}

//write a byte to SRAM

void sram_byte_write(long sramaddress, int sramdata) {

    int temp;
    sram_SS = 0;

    SPI2BUF = write;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress >> 16;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress >> 8;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramdata;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    sram_SS = 1;

}

//read a byte from SRAM

int sram_byte_read(long sramaddress) {

    int temp;

    sram_SS = 0;

    SPI2BUF = read;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress >> 16;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress >> 8;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = 255;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    sram_SS = 1;

    return (temp);

}

//write a 2 byte sequence to SRAM, must be in sequential mode

void sram_write(long sramaddress, int sramdata) {

    int temp;
    sram_SS = 0;

    SPI2BUF = write;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress >> 16;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress >> 8;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramdata >> 8;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramdata;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    sram_SS = 1;

}

//read a 2 byte sequence from SRAM, must be in sequential mode

int sram_read(long sramaddress) {

    int temp;

    sram_SS = 0;

    SPI2BUF = read;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress >> 16;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress >> 8;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = sramaddress;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF;

    SPI2BUF = 255;
    while (!SPI2STATbits.SPIRBF);
    temp = SPI2BUF << 8;

    SPI2BUF = 255;
    while (!SPI2STATbits.SPIRBF);
    temp = temp | SPI2BUF;

    sram_SS = 1;

    return (temp);

}