/* 
 * File:   dspic_hardware_definitions.h
 *
 *   Copyright © 2015 Ian Maltby
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */

#ifndef DSPIC_HARDWARE_DEFINITIONS_H
#define	DSPIC_HARDWARE_DEFINITIONS_H

//Selectable input sources
#define INT1_in RPINR0bits.INT1R
#define INT2_in RPINR1bits.INT2R
#define T2CK_in RPINR3bits.T2CKR
#define T3CK_in RPINR3bits.T3CKR
#define T4CK_in RPINR4bits.T4CKR
#define T5CK_in RPINR4bits.T5CKR
#define IC1_in RPINR7bits.IC1R
#define IC2_in  RPINR7bits.IC2R
#define IC7_in  RPINR10bits.IC7R
#define IC8_in RPINR10bits.IC8R
#define OCFA_in RPINR11bits.OCFAR
#define U1RX_in RPINR18bits.U1RXR
#define U1CTS_in RPINR18bits.U1CTSR
#define U2RX_in RPINR19bits.U2RXR
#define U2CTS_in RPINR19bits.U2CTSR
#define SDI1_in RPINR20bits.SDI1R
#define SCK1_in RPINR20bits.SCK1R
#define SS1_in RPINR21bits.SS1R
#define SDI2_in RPINR22bits.SDI2R
#define SCK2_in RPINR22bits.SCK2R
#define SS2_in RPINR23bits.SS2R
#define CSDI_in RPINR24bits.CSDIR
#define CSCK_in RPINR24bits.CSCKR
#define COFS_in RPINR25bits.COFSR
#define CIRX_in RPINR26bits.CIRXR

//Output selection for remappable pin (RPn)
#define C1OUT_out 1
#define C2OUT_out 2
#define U1TX_out 3
#define U1RTS_out 4
#define U2TX_out 5
#define U2RTS_out 6
#define SDO1_out 7
#define SCK1_out 8
#define SS1_out 9
#define SDO2_out 10
#define SCK2_out 11
#define SS2_out 12
#define CSDO_out 13
#define CSCK_out 14
#define COFS_out 15
#define C1TX_out 16
#define OC1_out 17
#define OC2_out 18
#define OC3_out 19
#define OC4_out 20

//Peripheral pin inputs
#define RPI0 0
#define RPI1 1
#define RPI2 2
#define RPI3 3
#define RPI4 4
#define RPI5 5
#define RPI6 6
#define RPI7 7
#define RPI8 8
#define RPI9 9
#define RPI10 10
#define RPI11 11
#define RPI12 12
#define RPI13 13
#define RPI14 14
#define RPI15 15
#define RPI16 16
#define RPI17 17
#define RPI18 18
#define RPI19 19
#define RPI20 20
#define RPI21 21
#define RPI22 22
#define RPI23 23
#define RPI24 24
#define RPI25 25

//Peripheral pin outputs
#define RPO0 RPOR0bits.RP0R
#define RPO1 RPOR0bits.RP1R
#define RPO2 RPOR1bits.RP2R
#define RPO3 RPOR1bits.RP3R
#define RPO4 RPOR2bits.RP4R
#define RPO5 RPOR2bits.RP5R
#define RPO6 RPOR3bits.RP6R
#define RPO7 RPOR3bits.RP7R
#define RPO8 RPOR4bits.RP8R
#define RPO9 RPOR4bits.RP9R
#define RPO10 RPOR5bits.RP10R
#define RPO11 RPOR5bits.RP11R
#define RPO12 RPOR6bits.RP12R
#define RPO13 RPOR6bits.RP13R
#define RPO14 RPOR7bits.RP14R
#define RPO15 RPOR7bits.RP15R
#define RPO16 RPOR8bits.RP16
#define RPO17 RPOR8bits.RP17R
#define RPO18 RPOR9bits.RP18R
#define RPO19 RPOR9bits.RP19R
#define RPO20 RPOR10bits.RP20R
#define RPO21 RPOR10bits.RP21R
#define RPO22 RPOR11bits.RP22R
#define RPO23 RPOR11bits.RP23R
#define RPO24 RPOR12bits.RP24R
#define RPO25 RPOR12bits.RP25R

#endif	/* DSPIC_HARDWARE_DEFINES_H */

