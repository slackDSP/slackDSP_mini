/* 
 * File:   sram.h
 * Author: Ian Maltby
 *
 * Created on December 11, 2014, 10:14 PM
 */

#ifndef SRAM_H
#define	SRAM_H

#define sram_SS LATAbits.LATA8 //SS SPI slave select
#define write 2
#define read 3
#define rdsr 5
#define wrsr 1
#define byte 0
#define seq 64

void sram_init(int sram_mode);
void sram_byte_write(long sramaddress, int sramdata);
int sram_byte_read(long sramaddress);
void sram_write(long sramaddress, int sramdata);
int sram_read(long sramaddress);

#endif	/* SRAM_H */

