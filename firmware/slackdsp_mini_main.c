/*
 *File:   slackdsp_mini_main.c
 *
 *   Copyright © 2015 Ian Maltby
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "dspic_hardware_definitions.h"
#include "WM8510.h"          //include WM8510 library
#include "sram.h"        //inlcude 23LC1024 library
#include "slackdsp_mini.h"   //include slackdsp library

// DSPIC33FJ128GP804 Configuration Bit Settings

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)
#pragma config RBS = NO_RAM             // Boot Segment RAM Protection (No Boot RAM)

// FSS
#pragma config SWRP = WRPROTECT_OFF     // Secure Segment Program Write Protect (Secure segment may be written)
#pragma config SSS = NO_FLASH           // Secure Segment Program Flash Code Protection (No Secure Segment)
#pragma config RSS = NO_RAM             // Secure Segment Data RAM Protection (No Secure RAM)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = FRCPLL           // Oscillator Mode (Internal Fast RC (FRC) w/ PLL)
#pragma config IESO = OFF               // Internal External Switch Over Mode (Start-up device with user-selected oscillator source)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Source (Primary Oscillator Disabled)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function (OSC2 pin has digital I/0 function)
#pragma config IOL1WAY = OFF            // Peripheral Pin Select Configuration (Allow Multiple Re-configurations)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)

int main(int argc, char** argv) {

    //setup internal clock for 80MHz/40MIPS using internal fast osc and PLL
    //7.37Mhz / 3 * 65 / 2 = 79.841666Mhz
    CLKDIVbits.PLLPRE = 1; //N1 = 3
    PLLFBD = 63; //M = 65
    CLKDIVbits.PLLPOST = 0; //N2 = 2
    while (!OSCCONbits.LOCK); //wait until PLL is locked

    //Setup IO pins
    AD1PCFGL = 0xFFFF; //set all pins digital
    RPO24 = OC2_out; //RP24 (pin 4) = PWM CLOCKOUT
    RPO9 = SDO1_out; //RP5 (pin 14) = SDO1
    RPO22 = SCK1_out; //RP6 (pin 15) = SCK1
    TRISCbits.TRISC7 = 0; //RC7 (Pin 16) = output = WM8510_SS (SPI slave select)
    RPO19 = SDO2_out; //RP19 (pin 36) = SDO2
    RPO20 = SCK2_out; //RP20 (pin 27) = SCK2
    SDI2_in = RPI4; //RP4 (pin 33) = SDI2
    TRISAbits.TRISA8 = 0; //RA8 (Pin 32) = output = sram_SS (SPI slave select)
    CSCK_in = RPI25; //RP9 (pin 18) = CSCLK << BCLCK
    COFS_in = RPI11; //RP10 (pin 21) = COFS << FRAME
    CSDI_in = RPI13; //RP12 (pin 23) = CSDI << ADCDAT
    RPO12 = CSDO_out; //RP11 (pin 22) = CSDO >> DACDAT

    TRISBbits.TRISB14 = 0;
    AD1PCFGLbits.PCFG4 = 0; //Set AN4 (pin 23) analogue = POT1
    AD1PCFGLbits.PCFG5 = 0; //Set AN5 (pin 24) analogue = POT2
    AD1PCFGLbits.PCFG6 = 0; //Set AN6 (pin 25) analogue = POT3

    //Initialise DCI module
    DCICON1bits.CSCKD = 1; //CSCK is an input
    DCICON1bits.COFSD = 1; //COFS is an input
    DCICON1bits.COFSM = 1; //I2S frame sync
    DCICON1bits.CSCKE = 1; //sample on rising edge
    DCICON1bits.DJST = 0; //data transmission starts 1 clock after frame
    DCICON2bits.BLEN = 3; //4 data words buffered between interrupts
    DCICON2bits.COFSG = 1; //data frame has 2 words
    DCICON2bits.WS = 15; //word data size is 16 bits
    TSCON = 3; //transmit in time slots 0 and 1
    RSCON = 3; //receive in time slots 0 and 1
    DCICON3 = 0;
    IPC15bits.DCIIP = 6; //Set DCI interrupt priority
    IFS3bits.DCIIF = 0; //clear DCI interrupt
    IEC3bits.DCIIE = 1; //enable DCI interrupt
    DCICON1bits.DCIEN = 1; //module enabled
    //DCICON1bits.DLOOP = 1; //loopback

    //Initialise output compare module 1 for PWM output (CLOCKOUT)
    OC1CONbits.OCM = 0; //disble module
    OC1R = 2; //default duty cycle
    OC1CONbits.OCTSEL = 0; //Select timer 2 as time base
    OC1CONbits.OCM = 0b110; //Select output mode PWM

    //Setup ADC module
    AD1CON2bits.VCFG = 0; //Ref = AVDD and AVSS
    AD1CON3bits.ADRC = 0; // Use system timer
    AD1CON3bits.ADCS = 2; //TAD = 3 * TCY
    AD1CON2bits.CHPS = 0; //Convert channel 0
    AD1CHS0bits.CH0SA = 4; //use AN4
    AD1CON1bits.ASAM = 1; //Auto sample
    AD1CON1bits.SSRC = 0; //manual convert
    AD1CON1bits.AD12B = 1; //12 bit sampling
    AD1CON1bits.FORM = 0; //unsigned integer format
    AD1CON1bits.ADON = 1; //ADC On

    //Initialise timer 2 - 10Mhz clock out to drive WM8510
    T2CONbits.TON = 0; //Disable timer
    T2CONbits.TCS = 0; //Select internal instruction cycle clock
    T2CONbits.TGATE = 0; //Disable gated mode
    T2CONbits.TCKPS = 0; //1:1 Prescaler
    TMR2 = 0; //Clear timer register
    PR2 = 3; //Load the period value PWM freq = 10Mhz
    IPC1bits.T2IP = 1; //Set timer 2 priority level
    IFS0bits.T2IF = 0; //Clear timer 2 interrupt flag
    T2CONbits.TON = 1; //Start timer 2

    //Initialise UART1
    U1MODE = 0; //Clear Uart 1 registers
    U1STA = 0; //to tidy up after bootloader
    U1RX_in = RPI1; //RP1 (pin 22) = RX
    RPO0 = U1TX_out; //RP0 (pin 21) = TX
    U1BRG = 259; //set baud rate to 9600
    U1MODEbits.URXINV = 1; //invert RX polarity
    U1STAbits.UTXINV = 1; //invert TX polartity
    IPC2bits.U1RXIP = 7; //set Uart 1 priorty level
    IFS0bits.U1RXIF = 0; //clear RX interrupt
    IFS0bits.U1TXIF = 0; //clear TX interrupt
    IEC0bits.U1RXIE = 1; //Enable RX interrupt
    IEC0bits.U1TXIE = 0; //Disable TX interrupt
    U1MODEbits.UARTEN = 1; //Enable Uart 1
    U1STAbits.UTXEN = 1; //Enable TX

    CLOCKOUT = 2;
    LED = 1;

    WM8510_init(); //initialise WM8510 port
    sram_init(seq); //initilise 23LC1024 in sequential mode

    //Configure WM8510
    WM8510_write(software_reset, 0); //reset
    WM8510_write(power_mngmnt1, 79); //mic2 on, bias on, tie off buffer enabled, vmid 5k
    WM8510_write(power_mngmnt2, 17); //Boost on, ADC on
    WM8510_write(power_mngmnt3, 137); //mono out on, mono mixer on, DAC on
    WM8510_write(input_ctrl, 8); //mic2 = mixer

    //PLL setup to generate 8.192Mhz clock for 32kHz sample rate
    WM8510_write(pll_n, 9); //PLL n = 9
    WM8510_write(pll_k1, 53);
    WM8510_write(pll_k2, 74);
    WM8510_write(pll_k3, 280);
    WM8510_write(clock_gen_ctrl, 361); //PLL output, PLL/3, BCCLK/4, Frame master
    WM8510_write(power_mngmnt1, 111); //PLL on

    WM8510_write(audio_interface, 208); //frame clock inverted, word length 24bits, I2S format
    WM8510_write(adc_boost_ctrl, 5); //input boost 0dB
    // WM8510_write(companding_ctrl, 1); //Loopback
    WM8510_write(dac_control, 24); //32khz de-emphasis, 128x DAC oversample
    WM8510_write(adc_control, 264); //hipass on (removes any audio DC offset), 128x ADC oversample
    WM8510_write(additional_ctrl, 2); //32Khz sample rate
    WM8510_write(mono_mixer_ctrl, 1); //DAC to mono mixer


    for (;;) {

        //do nothing

    }

    return (EXIT_SUCCESS);
}

//DCI ISR

void __attribute__((interrupt, no_auto_psv)) _DCIInterrupt(void) {

    static int dummy = 0;
    static long adc = 0;
    static int sample = 0;
    static int sample1 = 0;
    static int sample2 = 0;
    static long pot_sample = 0;
    static long pots[3] = {0, 0, 0};
    static int pot_select = 0;
    IFS3bits.DCIIF = 0; //clear DCI interrupt

    AD1CON1bits.SAMP = 0;
    while (!AD1CON1bits.DONE);
    AD1CON1bits.DONE = 0;
    pot_sample = ADC;
    if (pot_sample >> 4 == (pot_sample + 4) >> 4)
        pots[pot_select] = (pot_sample << 3) & 32640;

    pot_select++;
    if (pot_select == 3)
        pot_select = 0;

    AD1CHS0bits.CH0SA = pot_select + 4;

    TXBUF0 = sample;
    TXBUF1 = 0;
    TXBUF2 = 0;
    TXBUF3 = 0;

    adc = RXBUF0;
    adc = (adc << 16) | (RXBUF1);
    dummy = RXBUF2;
    dummy = RXBUF3;

    adc = (adc + 32768) >> 16;
    if (adc > 32767)
        adc = 32767;

    sample = adc;

    /*Effect code start*/

    int mode = 0;

    mode = pot3 >> 12;

    if (mode == 0) {

        sample = sample;

    }

    if (mode == 1) {

        sample1 = add(sample, mulx(logpot(pot2), sample1));
        sample1 = delayline(131072, pot1 << 2, 0, sample1);
        sample = add(sample, mulx(pot2, sample1));

    }

    if (mode == 2) {

        sample1 = pitchshift(8192, sample);
        sample1 = lowpass(10632, sample1);
        sample2 = pitchshift2(32767, sample);
        sample1 = blend(pot1, sample1, sample2);
        sample = blend(pot2, sample, sample1);

    }

    if (mode == 3) {

        sample = svf((random_lfo(pot1) >> 1) + 2000, pot2, lp, sample);

    }

    if (mode == 4) {

        sample1 = mulx(vco(logpot(pot1) >> 2), sample);
        sample = blend(pot2, sample, sample1);

    }

    if (mode == 5) {

        sample1 = revdelay(131072, pot1 << 2, sample);
        sample = blend(pot2, sample, sample1);

    }

    if (mode == 6) {

#define long_flange 1024
#define short_flange 40
#define flange_range 800
        static int feedback = 0;

        sample1 = add(sample, mulx(feedback, 30000));
        sample1 = delayline(long_flange, short_flange + mulx(hyper_tri_lfo(logpot(pot1)), flange_range), 0, sample1);
        feedback = mulx((pot2 - 16384) << 1, sample1);
        sample = add(sample, sample1);

    }

    if (mode == 7) {

        int scale[8] = {16384, 18390, 20642, 21870, 24548, 27554, 30928, 32767};
        static int pitch = 0;

        pitch = random_lfo(pot1) >> 12;
        sample1 = pitchshift(scale[pitch], sample);
        sample = blend(pot2, sample, sample1);

    }

    /*Effect code end*/

}

//UART1 ISR

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void) {

    const char version[] = "slackDSP mini ("codename")\nBuilt: "__DATE__"\n"; //ignore warning compiles OK
    const char *i;

    IFS0bits.U1RXIF = 0; //clear RX1 interrupt

    if (U1RXREG == 123) //reset the PIC if "{" (ASCII 123) is received
        asm("reset");

    if (U1RXREG == 118) {
        i = version;
        while (*i) {
            while (U1STAbits.UTXBF);
            U1TXREG = *i;
            i++;
        }
    }
} 