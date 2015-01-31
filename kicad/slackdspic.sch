EESchema Schematic File Version 2  date Tue 23 Dec 2014 08:42:44 PM GMT
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:slackDSP
LIBS:slackdspic-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "slackdspic"
Date "27 nov 2014"
Rev "1"
Comp "slackDSP"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DSPIC33FJ128GP804 U1
U 1 1 54401A79
P 2250 3300
F 0 "U1" H 2250 5250 60  0000 C CNN
F 1 "DSPIC33FJ128GP804" H 2250 1350 60  0000 C CNN
F 2 "~" H 2250 3300 60  0000 C CNN
F 3 "~" H 2250 3300 60  0000 C CNN
	1    2250 3300
	1    0    0    -1  
$EndComp
$Comp
L WM8510 U2
U 1 1 54401A88
P 5400 3150
F 0 "U2" H 5400 5100 60  0000 C CNN
F 1 "WM8510" H 5400 3050 60  0000 C CNN
F 2 "~" H 6250 3900 60  0000 C CNN
F 3 "~" H 6250 3900 60  0000 C CNN
	1    5400 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR7
U 1 1 544022D5
P 1050 3650
F 0 "#PWR7" H 1050 3650 30  0001 C CNN
F 1 "GND" H 1050 3580 30  0001 C CNN
F 2 "" H 1050 3650 60  0000 C CNN
F 3 "" H 1050 3650 60  0000 C CNN
	1    1050 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 54402518
P 850 1850
F 0 "#PWR1" H 850 1850 30  0001 C CNN
F 1 "GND" H 850 1780 30  0001 C CNN
F 2 "" H 850 1850 60  0000 C CNN
F 3 "" H 850 1850 60  0000 C CNN
	1    850  1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 54402527
P 900 2450
F 0 "#PWR2" H 900 2450 30  0001 C CNN
F 1 "GND" H 900 2380 30  0001 C CNN
F 2 "" H 900 2450 60  0000 C CNN
F 3 "" H 900 2450 60  0000 C CNN
	1    900  2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 54402536
P 1050 3050
F 0 "#PWR6" H 1050 3050 30  0001 C CNN
F 1 "GND" H 1050 2980 30  0001 C CNN
F 2 "" H 1050 3050 60  0000 C CNN
F 3 "" H 1050 3050 60  0000 C CNN
	1    1050 3050
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 54402587
P 850 2700
F 0 "C4" H 850 2800 40  0000 L CNN
F 1 "100n" H 856 2615 40  0000 L CNN
F 2 "~" H 888 2550 30  0000 C CNN
F 3 "~" H 850 2700 60  0000 C CNN
	1    850  2700
	0    -1   -1   0   
$EndComp
$Comp
L C C3
U 1 1 54402596
P 850 2100
F 0 "C3" H 850 2200 40  0000 L CNN
F 1 "100n" H 856 2015 40  0000 L CNN
F 2 "~" H 888 1950 30  0000 C CNN
F 3 "~" H 850 2100 60  0000 C CNN
	1    850  2100
	0    -1   -1   0   
$EndComp
$Comp
L C C2
U 1 1 544025A5
P 850 1500
F 0 "C2" H 850 1600 40  0000 L CNN
F 1 "100n" H 856 1415 40  0000 L CNN
F 2 "~" H 888 1350 30  0000 C CNN
F 3 "~" H 850 1500 60  0000 C CNN
	1    850  1500
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR29
U 1 1 54402B14
P 6850 1950
F 0 "#PWR29" H 6850 1950 30  0001 C CNN
F 1 "GND" H 6850 1880 30  0001 C CNN
F 2 "" H 6850 1950 60  0000 C CNN
F 3 "" H 6850 1950 60  0000 C CNN
	1    6850 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR28
U 1 1 54402CDA
P 6750 2550
F 0 "#PWR28" H 6750 2550 30  0001 C CNN
F 1 "GND" H 6750 2480 30  0001 C CNN
F 2 "" H 6750 2550 60  0000 C CNN
F 3 "" H 6750 2550 60  0000 C CNN
	1    6750 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR26
U 1 1 54402E1A
P 6550 3150
F 0 "#PWR26" H 6550 3150 30  0001 C CNN
F 1 "GND" H 6550 3080 30  0001 C CNN
F 2 "" H 6550 3150 60  0000 C CNN
F 3 "" H 6550 3150 60  0000 C CNN
	1    6550 3150
	1    0    0    -1  
$EndComp
NoConn ~ 4600 2300
NoConn ~ 4600 2400
NoConn ~ 4600 2500
NoConn ~ 4600 2800
NoConn ~ 4600 2900
$Comp
L VCC #PWR24
U 1 1 54403269
P 6450 1550
F 0 "#PWR24" H 6450 1650 30  0001 C CNN
F 1 "VCC" H 6450 1650 30  0000 C CNN
F 2 "" H 6450 1550 60  0000 C CNN
F 3 "" H 6450 1550 60  0000 C CNN
	1    6450 1550
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR25
U 1 1 5440333D
P 6550 2100
F 0 "#PWR25" H 6550 2200 30  0001 C CNN
F 1 "VCC" H 6550 2200 30  0000 C CNN
F 2 "" H 6550 2100 60  0000 C CNN
F 3 "" H 6550 2100 60  0000 C CNN
	1    6550 2100
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR23
U 1 1 544033BD
P 6250 2650
F 0 "#PWR23" H 6250 2750 30  0001 C CNN
F 1 "VCC" H 6250 2750 30  0000 C CNN
F 2 "" H 6250 2650 60  0000 C CNN
F 3 "" H 6250 2650 60  0000 C CNN
	1    6250 2650
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR3
U 1 1 54403405
P 1050 1350
F 0 "#PWR3" H 1050 1450 30  0001 C CNN
F 1 "VCC" H 1050 1450 30  0000 C CNN
F 2 "" H 1050 1350 60  0000 C CNN
F 3 "" H 1050 1350 60  0000 C CNN
	1    1050 1350
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR4
U 1 1 54403414
P 1050 2000
F 0 "#PWR4" H 1050 2100 30  0001 C CNN
F 1 "VCC" H 1050 2100 30  0000 C CNN
F 2 "" H 1050 2000 60  0000 C CNN
F 3 "" H 1050 2000 60  0000 C CNN
	1    1050 2000
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR5
U 1 1 54403423
P 1050 2600
F 0 "#PWR5" H 1050 2700 30  0001 C CNN
F 1 "VCC" H 1050 2700 30  0000 C CNN
F 2 "" H 1050 2600 60  0000 C CNN
F 3 "" H 1050 2600 60  0000 C CNN
	1    1050 2600
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 544034E3
P 1050 4200
F 0 "R1" V 1130 4200 40  0000 C CNN
F 1 "10k" V 1057 4201 40  0000 C CNN
F 2 "~" V 980 4200 30  0000 C CNN
F 3 "~" H 1050 4200 30  0000 C CNN
	1    1050 4200
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR8
U 1 1 544039A2
P 1050 3950
F 0 "#PWR8" H 1050 4050 30  0001 C CNN
F 1 "VCC" H 1050 4050 30  0000 C CNN
F 2 "" H 1050 3950 60  0000 C CNN
F 3 "" H 1050 3950 60  0000 C CNN
	1    1050 3950
	1    0    0    -1  
$EndComp
NoConn ~ 3450 2000
$Comp
L R R3
U 1 1 54414250
P 4600 1150
F 0 "R3" V 4680 1150 40  0000 C CNN
F 1 "10k" V 4607 1151 40  0000 C CNN
F 2 "~" V 4530 1150 30  0000 C CNN
F 3 "~" H 4600 1150 30  0000 C CNN
	1    4600 1150
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR17
U 1 1 5441425F
P 4600 900
F 0 "#PWR17" H 4600 1000 30  0001 C CNN
F 1 "VCC" H 4600 1000 30  0000 C CNN
F 2 "" H 4600 900 60  0000 C CNN
F 3 "" H 4600 900 60  0000 C CNN
	1    4600 900 
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 54414337
P 3950 1500
F 0 "R2" V 4030 1500 40  0000 C CNN
F 1 "10k" V 3957 1501 40  0000 C CNN
F 2 "~" V 3880 1500 30  0000 C CNN
F 3 "~" H 3950 1500 30  0000 C CNN
	1    3950 1500
	0    -1   -1   0   
$EndComp
$Comp
L VCC #PWR15
U 1 1 54414389
P 3700 1500
F 0 "#PWR15" H 3700 1600 30  0001 C CNN
F 1 "VCC" H 3700 1600 30  0000 C CNN
F 2 "" H 3700 1500 60  0000 C CNN
F 3 "" H 3700 1500 60  0000 C CNN
	1    3700 1500
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 54428734
P 6650 1700
F 0 "C7" H 6700 1800 50  0000 L CNN
F 1 "10u" H 6700 1600 50  0000 L CNN
F 2 "~" H 6650 1700 60  0000 C CNN
F 3 "~" H 6650 1700 60  0000 C CNN
	1    6650 1700
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 54428743
P 6950 1700
F 0 "C9" H 7000 1800 50  0000 L CNN
F 1 "10u" H 7000 1600 50  0000 L CNN
F 2 "~" H 6950 1700 60  0000 C CNN
F 3 "~" H 6950 1700 60  0000 C CNN
	1    6950 1700
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 54428752
P 6400 2300
F 0 "C5" H 6450 2400 50  0000 L CNN
F 1 "10u" H 6450 2200 50  0000 L CNN
F 2 "~" H 6400 2300 60  0000 C CNN
F 3 "~" H 6400 2300 60  0000 C CNN
	1    6400 2300
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 54428761
P 6750 2300
F 0 "C8" H 6800 2400 50  0000 L CNN
F 1 "10u" H 6800 2200 50  0000 L CNN
F 2 "~" H 6750 2300 60  0000 C CNN
F 3 "~" H 6750 2300 60  0000 C CNN
	1    6750 2300
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 54428770
P 6550 2900
F 0 "C6" H 6600 3000 50  0000 L CNN
F 1 "10u" H 6600 2800 50  0000 L CNN
F 2 "~" H 6550 2900 60  0000 C CNN
F 3 "~" H 6550 2900 60  0000 C CNN
	1    6550 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR40
U 1 1 54428B3B
P 9050 6250
F 0 "#PWR40" H 9050 6250 30  0001 C CNN
F 1 "GND" H 9050 6180 30  0001 C CNN
F 2 "" H 9050 6250 60  0000 C CNN
F 3 "" H 9050 6250 60  0000 C CNN
	1    9050 6250
	1    0    0    -1  
$EndComp
$Comp
L DIODE D2
U 1 1 54428B93
P 9050 5400
F 0 "D2" H 9050 5500 40  0000 C CNN
F 1 "LL4001" H 9050 5300 40  0000 C CNN
F 2 "~" H 9050 5400 60  0000 C CNN
F 3 "~" H 9050 5400 60  0000 C CNN
	1    9050 5400
	-1   0    0    1   
$EndComp
$Comp
L DIODE D1
U 1 1 54428BA2
P 8100 5800
F 0 "D1" H 8100 5900 40  0000 C CNN
F 1 "LL4001" H 8100 5700 40  0000 C CNN
F 2 "~" H 8100 5800 60  0000 C CNN
F 3 "~" H 8100 5800 60  0000 C CNN
	1    8100 5800
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 54428E8A
P 9650 6000
F 0 "C11" H 9700 6100 50  0000 L CNN
F 1 "10u" H 9700 5900 50  0000 L CNN
F 2 "~" H 9650 6000 60  0000 C CNN
F 3 "~" H 9650 6000 60  0000 C CNN
	1    9650 6000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR41
U 1 1 54428EA1
P 9650 6250
F 0 "#PWR41" H 9650 6250 30  0001 C CNN
F 1 "GND" H 9650 6180 30  0001 C CNN
F 2 "" H 9650 6250 60  0000 C CNN
F 3 "" H 9650 6250 60  0000 C CNN
	1    9650 6250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR44
U 1 1 54428F47
P 9900 5800
F 0 "#PWR44" H 9900 5900 30  0001 C CNN
F 1 "VCC" H 9900 5900 30  0000 C CNN
F 2 "" H 9900 5800 60  0000 C CNN
F 3 "" H 9900 5800 60  0000 C CNN
	1    9900 5800
	1    0    0    -1  
$EndComp
$Comp
L CP1 C10
U 1 1 54428F54
P 8500 6000
F 0 "C10" H 8550 6100 50  0000 L CNN
F 1 "100u" H 8550 5900 50  0000 L CNN
F 2 "~" H 8500 6000 60  0000 C CNN
F 3 "~" H 8500 6000 60  0000 C CNN
	1    8500 6000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR37
U 1 1 54428F5A
P 8500 6250
F 0 "#PWR37" H 8500 6250 30  0001 C CNN
F 1 "GND" H 8500 6180 30  0001 C CNN
F 2 "" H 8500 6250 60  0000 C CNN
F 3 "" H 8500 6250 60  0000 C CNN
	1    8500 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR31
U 1 1 54428FBA
P 7900 6250
F 0 "#PWR31" H 7900 6250 30  0001 C CNN
F 1 "GND" H 7900 6180 30  0001 C CNN
F 2 "" H 7900 6250 60  0000 C CNN
F 3 "" H 7900 6250 60  0000 C CNN
	1    7900 6250
	1    0    0    -1  
$EndComp
$Comp
L 7833 U3
U 1 1 54429389
P 9050 5850
F 0 "U3" H 9200 5654 60  0000 C CNN
F 1 "7833" H 9050 6050 60  0000 C CNN
F 2 "~" H 9050 5850 60  0000 C CNN
F 3 "~" H 9050 5850 60  0000 C CNN
	1    9050 5850
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 544297EE
P 2750 7000
F 0 "R7" V 2830 7000 40  0000 C CNN
F 1 "3k3" V 2757 7001 40  0000 C CNN
F 2 "~" V 2680 7000 30  0000 C CNN
F 3 "~" H 2750 7000 30  0000 C CNN
	1    2750 7000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR14
U 1 1 544297FD
P 2750 7250
F 0 "#PWR14" H 2750 7250 30  0001 C CNN
F 1 "GND" H 2750 7180 30  0001 C CNN
F 2 "" H 2750 7250 60  0000 C CNN
F 3 "" H 2750 7250 60  0000 C CNN
	1    2750 7250
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR35
U 1 1 5442980C
P 8400 5650
F 0 "#PWR35" H 8400 5620 20  0001 C CNN
F 1 "+9V" H 8400 5760 30  0000 C CNN
F 2 "" H 8400 5650 60  0000 C CNN
F 3 "" H 8400 5650 60  0000 C CNN
	1    8400 5650
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR13
U 1 1 544298C3
P 2750 5900
F 0 "#PWR13" H 2750 5870 20  0001 C CNN
F 1 "+9V" H 2750 6010 30  0000 C CNN
F 2 "" H 2750 5900 60  0000 C CNN
F 3 "" H 2750 5900 60  0000 C CNN
	1    2750 5900
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 54429927
P 2050 6400
F 0 "R6" V 2130 6400 40  0000 C CNN
F 1 "10k" V 2057 6401 40  0000 C CNN
F 2 "~" V 1980 6400 30  0000 C CNN
F 3 "~" H 2050 6400 30  0000 C CNN
	1    2050 6400
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 54429936
P 1800 6650
F 0 "R5" V 1880 6650 40  0000 C CNN
F 1 "2M2" V 1807 6651 40  0000 C CNN
F 2 "~" V 1730 6650 30  0000 C CNN
F 3 "~" H 1800 6650 30  0000 C CNN
	1    1800 6650
	1    0    0    -1  
$EndComp
$Comp
L C C12
U 1 1 54429945
P 1600 6400
F 0 "C12" H 1600 6500 40  0000 L CNN
F 1 "100n" H 1606 6315 40  0000 L CNN
F 2 "~" H 1638 6250 30  0000 C CNN
F 3 "~" H 1600 6400 60  0000 C CNN
	1    1600 6400
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR9
U 1 1 544299BB
P 1150 6700
F 0 "#PWR9" H 1150 6700 30  0001 C CNN
F 1 "GND" H 1150 6630 30  0001 C CNN
F 2 "" H 1150 6700 60  0000 C CNN
F 3 "" H 1150 6700 60  0000 C CNN
	1    1150 6700
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 54429A20
P 1800 6150
F 0 "R4" V 1880 6150 40  0000 C CNN
F 1 "2M2" V 1807 6151 40  0000 C CNN
F 2 "~" V 1730 6150 30  0000 C CNN
F 3 "~" H 1800 6150 30  0000 C CNN
	1    1800 6150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR12
U 1 1 54429A2F
P 1800 6900
F 0 "#PWR12" H 1800 6900 30  0001 C CNN
F 1 "GND" H 1800 6830 30  0001 C CNN
F 2 "" H 1800 6900 60  0000 C CNN
F 3 "" H 1800 6900 60  0000 C CNN
	1    1800 6900
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR11
U 1 1 54429A3C
P 1800 5900
F 0 "#PWR11" H 1800 5870 20  0001 C CNN
F 1 "+9V" H 1800 6010 30  0000 C CNN
F 2 "" H 1800 5900 60  0000 C CNN
F 3 "" H 1800 5900 60  0000 C CNN
	1    1800 5900
	1    0    0    -1  
$EndComp
$Comp
L C C13
U 1 1 54429B49
P 2950 6750
F 0 "C13" H 2950 6850 40  0000 L CNN
F 1 "1u" H 2956 6665 40  0000 L CNN
F 2 "~" H 2988 6600 30  0000 C CNN
F 3 "~" H 2950 6750 60  0000 C CNN
	1    2950 6750
	0    -1   -1   0   
$EndComp
$Comp
L R R8
U 1 1 54429B58
P 3400 6750
F 0 "R8" V 3480 6750 40  0000 C CNN
F 1 "22k" V 3407 6751 40  0000 C CNN
F 2 "~" V 3330 6750 30  0000 C CNN
F 3 "~" H 3400 6750 30  0000 C CNN
	1    3400 6750
	0    -1   -1   0   
$EndComp
Text GLabel 3650 6750 2    60   Input ~ 0
MIC2
Text GLabel 4400 2700 0    60   Input ~ 0
MIC2
Text GLabel 4450 3000 0    60   Input ~ 0
MONOOUT
Text GLabel 4550 6750 0    60   Input ~ 0
MONOOUT
$Comp
L R R9
U 1 1 54429C18
P 4800 6750
F 0 "R9" V 4880 6750 40  0000 C CNN
F 1 "100r" V 4807 6751 40  0000 C CNN
F 2 "~" V 4730 6750 30  0000 C CNN
F 3 "~" H 4800 6750 30  0000 C CNN
	1    4800 6750
	0    -1   -1   0   
$EndComp
$Comp
L C C14
U 1 1 54429C27
P 5250 6750
F 0 "C14" H 5250 6850 40  0000 L CNN
F 1 "1u" H 5256 6665 40  0000 L CNN
F 2 "~" H 5288 6600 30  0000 C CNN
F 3 "~" H 5250 6750 60  0000 C CNN
	1    5250 6750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR21
U 1 1 54429C96
P 5700 7050
F 0 "#PWR21" H 5700 7050 30  0001 C CNN
F 1 "GND" H 5700 6980 30  0001 C CNN
F 2 "" H 5700 7050 60  0000 C CNN
F 3 "" H 5700 7050 60  0000 C CNN
	1    5700 7050
	1    0    0    -1  
$EndComp
Text GLabel 3600 3100 2    60   Input ~ 0
DATA
Text GLabel 3650 3300 2    60   Input ~ 0
CLOCK
Text GLabel 900  4450 0    60   Input ~ 0
MCLR
Text GLabel 8200 1350 0    60   Input ~ 0
MCLR
Text GLabel 8200 1800 0    60   Input ~ 0
DATA
Text GLabel 7800 2300 0    60   Input ~ 0
CLOCK
$Comp
L GND #PWR34
U 1 1 5443B087
P 8300 1600
F 0 "#PWR34" H 8300 1600 30  0001 C CNN
F 1 "GND" H 8300 1530 30  0001 C CNN
F 2 "" H 8300 1600 60  0000 C CNN
F 3 "" H 8300 1600 60  0000 C CNN
	1    8300 1600
	1    0    0    -1  
$EndComp
NoConn ~ 3450 4700
NoConn ~ 3450 4800
NoConn ~ 3450 4900
NoConn ~ 3450 5000
NoConn ~ 3450 2900
NoConn ~ 3450 3000
$Comp
L R R10
U 1 1 5445490A
P 8050 2300
F 0 "R10" V 8130 2300 40  0000 C CNN
F 1 "22k" V 8057 2301 40  0000 C CNN
F 2 "~" V 7980 2300 30  0000 C CNN
F 3 "~" H 8050 2300 30  0000 C CNN
	1    8050 2300
	0    -1   -1   0   
$EndComp
$Comp
L R R11
U 1 1 5445492B
P 8050 2500
F 0 "R11" V 8130 2500 40  0000 C CNN
F 1 "100r" V 8057 2501 40  0000 C CNN
F 2 "~" V 7980 2500 30  0000 C CNN
F 3 "~" H 8050 2500 30  0000 C CNN
	1    8050 2500
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR36
U 1 1 54454C21
P 8500 2700
F 0 "#PWR36" H 8500 2700 30  0001 C CNN
F 1 "GND" H 8500 2630 30  0001 C CNN
F 2 "" H 8500 2700 60  0000 C CNN
F 3 "" H 8500 2700 60  0000 C CNN
	1    8500 2700
	1    0    0    -1  
$EndComp
NoConn ~ 3450 2500
NoConn ~ 3450 2600
NoConn ~ 3450 2800
Text GLabel 7800 2500 0    60   Input ~ 0
DATA
Text GLabel 8200 2000 0    60   Input ~ 0
CLOCK
Text Notes 9100 1650 0    60   ~ 0
ICSP
Text Notes 9000 2550 0    60   ~ 0
SERIAL
Text Notes 550  6550 0    60   ~ 0
IN
Text Notes 6250 6900 0    60   ~ 0
OUT
Text Notes 7100 5950 0    60   ~ 0
DC IN
$Comp
L 23LC1024 U4
U 1 1 544563BB
P 5450 4700
F 0 "U4" H 5600 5050 60  0000 C CNN
F 1 "23LC1024" H 5450 4400 60  0000 C CNN
F 2 "" H 5450 4750 60  0000 C CNN
F 3 "" H 5450 4750 60  0000 C CNN
	1    5450 4700
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR22
U 1 1 544563C8
P 6150 4100
F 0 "#PWR22" H 6150 4200 30  0001 C CNN
F 1 "VCC" H 6150 4200 30  0000 C CNN
F 2 "" H 6150 4100 60  0000 C CNN
F 3 "" H 6150 4100 60  0000 C CNN
	1    6150 4100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR19
U 1 1 5445651A
P 4750 4900
F 0 "#PWR19" H 4750 4900 30  0001 C CNN
F 1 "GND" H 4750 4830 30  0001 C CNN
F 2 "" H 4750 4900 60  0000 C CNN
F 3 "" H 4750 4900 60  0000 C CNN
	1    4750 4900
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 54456591
P 4200 4450
F 0 "R12" V 4280 4450 40  0000 C CNN
F 1 "10k" V 4207 4451 40  0000 C CNN
F 2 "~" V 4130 4450 30  0000 C CNN
F 3 "~" H 4200 4450 30  0000 C CNN
	1    4200 4450
	-1   0    0    1   
$EndComp
$Comp
L R R13
U 1 1 544565A8
P 4750 4250
F 0 "R13" V 4830 4250 40  0000 C CNN
F 1 "10k" V 4757 4251 40  0000 C CNN
F 2 "~" V 4680 4250 30  0000 C CNN
F 3 "~" H 4750 4250 30  0000 C CNN
	1    4750 4250
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR18
U 1 1 544565AE
P 4750 4000
F 0 "#PWR18" H 4750 4100 30  0001 C CNN
F 1 "VCC" H 4750 4100 30  0000 C CNN
F 2 "" H 4750 4000 60  0000 C CNN
F 3 "" H 4750 4000 60  0000 C CNN
	1    4750 4000
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR16
U 1 1 544565B4
P 4200 4200
F 0 "#PWR16" H 4200 4300 30  0001 C CNN
F 1 "VCC" H 4200 4300 30  0000 C CNN
F 2 "" H 4200 4200 60  0000 C CNN
F 3 "" H 4200 4200 60  0000 C CNN
	1    4200 4200
	1    0    0    -1  
$EndComp
Text GLabel 4600 4600 0    60   Input ~ 0
SDI
Text GLabel 4500 4300 0    60   Input ~ 0
CS
Text GLabel 6300 4600 2    60   Input ~ 0
SCK
Text GLabel 6300 4800 2    60   Input ~ 0
SDO
$Comp
L C C15
U 1 1 54456883
P 6350 4250
F 0 "C15" H 6350 4350 40  0000 L CNN
F 1 "100n" H 6356 4165 40  0000 L CNN
F 2 "~" H 6388 4100 30  0000 C CNN
F 3 "~" H 6350 4250 60  0000 C CNN
	1    6350 4250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR27
U 1 1 5445690A
P 6550 4350
F 0 "#PWR27" H 6550 4350 30  0001 C CNN
F 1 "GND" H 6550 4280 30  0001 C CNN
F 2 "" H 6550 4350 60  0000 C CNN
F 3 "" H 6550 4350 60  0000 C CNN
	1    6550 4350
	1    0    0    -1  
$EndComp
Text GLabel 3750 3950 2    60   Input ~ 0
CS
Text GLabel 3750 4100 2    60   Input ~ 0
SDI
Text GLabel 3600 4500 2    60   Input ~ 0
SCK
Text GLabel 3600 4300 2    60   Input ~ 0
SDO
NoConn ~ 3450 4300
NoConn ~ 3450 4200
NoConn ~ 1050 4750
$Comp
L POT RV1
U 1 1 544586CA
P 8050 3500
F 0 "RV1" H 8050 3400 50  0000 C CNN
F 1 "10k Lin" H 8050 3500 50  0000 C CNN
F 2 "~" H 8050 3500 60  0000 C CNN
F 3 "~" H 8050 3500 60  0000 C CNN
	1    8050 3500
	0    -1   -1   0   
$EndComp
$Comp
L POT RV2
U 1 1 544586D7
P 8900 3500
F 0 "RV2" H 8900 3400 50  0000 C CNN
F 1 "10k lin" H 8900 3500 50  0000 C CNN
F 2 "~" H 8900 3500 60  0000 C CNN
F 3 "~" H 8900 3500 60  0000 C CNN
	1    8900 3500
	0    -1   -1   0   
$EndComp
$Comp
L POT RV3
U 1 1 544586DD
P 9750 3500
F 0 "RV3" H 9750 3400 50  0000 C CNN
F 1 "10k lin" H 9750 3500 50  0000 C CNN
F 2 "~" H 9750 3500 60  0000 C CNN
F 3 "~" H 9750 3500 60  0000 C CNN
	1    9750 3500
	0    -1   -1   0   
$EndComp
$Comp
L VCC #PWR32
U 1 1 544586E3
P 8050 3250
F 0 "#PWR32" H 8050 3350 30  0001 C CNN
F 1 "VCC" H 8050 3350 30  0000 C CNN
F 2 "" H 8050 3250 60  0000 C CNN
F 3 "" H 8050 3250 60  0000 C CNN
	1    8050 3250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR38
U 1 1 544586E9
P 8900 3250
F 0 "#PWR38" H 8900 3350 30  0001 C CNN
F 1 "VCC" H 8900 3350 30  0000 C CNN
F 2 "" H 8900 3250 60  0000 C CNN
F 3 "" H 8900 3250 60  0000 C CNN
	1    8900 3250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR42
U 1 1 544586EF
P 9750 3250
F 0 "#PWR42" H 9750 3350 30  0001 C CNN
F 1 "VCC" H 9750 3350 30  0000 C CNN
F 2 "" H 9750 3250 60  0000 C CNN
F 3 "" H 9750 3250 60  0000 C CNN
	1    9750 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR33
U 1 1 544586F5
P 8050 3750
F 0 "#PWR33" H 8050 3750 30  0001 C CNN
F 1 "GND" H 8050 3680 30  0001 C CNN
F 2 "" H 8050 3750 60  0000 C CNN
F 3 "" H 8050 3750 60  0000 C CNN
	1    8050 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR39
U 1 1 544586FB
P 8900 3750
F 0 "#PWR39" H 8900 3750 30  0001 C CNN
F 1 "GND" H 8900 3680 30  0001 C CNN
F 2 "" H 8900 3750 60  0000 C CNN
F 3 "" H 8900 3750 60  0000 C CNN
	1    8900 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR43
U 1 1 54458701
P 9750 3750
F 0 "#PWR43" H 9750 3750 30  0001 C CNN
F 1 "GND" H 9750 3680 30  0001 C CNN
F 2 "" H 9750 3750 60  0000 C CNN
F 3 "" H 9750 3750 60  0000 C CNN
	1    9750 3750
	1    0    0    -1  
$EndComp
Text GLabel 7800 3500 0    60   Input ~ 0
POT1
Text GLabel 8650 3500 0    60   Input ~ 0
POT2
Text GLabel 9500 3500 0    60   Input ~ 0
POT3
Text GLabel 3750 3500 2    60   Input ~ 0
POT1
Text GLabel 3750 3650 2    60   Input ~ 0
POT2
Text GLabel 3750 3800 2    60   Input ~ 0
POT3
NoConn ~ 3450 3700
NoConn ~ 3450 3800
Text GLabel 3600 2700 2    60   Input ~ 0
LED
$Comp
L LED D3
U 1 1 54458E08
P 7600 4600
F 0 "D3" H 7600 4700 50  0000 C CNN
F 1 "LED" H 7600 4500 50  0000 C CNN
F 2 "~" H 7600 4600 60  0000 C CNN
F 3 "~" H 7600 4600 60  0000 C CNN
	1    7600 4600
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 54458E17
P 7600 4150
F 0 "R14" V 7680 4150 40  0000 C CNN
F 1 "10k" V 7607 4151 40  0000 C CNN
F 2 "~" V 7530 4150 30  0000 C CNN
F 3 "~" H 7600 4150 30  0000 C CNN
	1    7600 4150
	1    0    0    -1  
$EndComp
Text GLabel 7450 3800 0    60   Input ~ 0
LED
$Comp
L CONN_2 P4
U 1 1 54458EB5
P 7950 4900
F 0 "P4" V 7900 4900 40  0000 C CNN
F 1 "LED" V 8000 4900 40  0000 C CNN
F 2 "" H 7950 4900 60  0000 C CNN
F 3 "" H 7950 4900 60  0000 C CNN
	1    7950 4900
	1    0    0    1   
$EndComp
$Comp
L GND #PWR30
U 1 1 54458FE2
P 7600 5100
F 0 "#PWR30" H 7600 5100 30  0001 C CNN
F 1 "GND" H 7600 5030 30  0001 C CNN
F 2 "" H 7600 5100 60  0000 C CNN
F 3 "" H 7600 5100 60  0000 C CNN
	1    7600 5100
	1    0    0    -1  
$EndComp
Text Notes 8150 4950 0    60   ~ 0
LED
$Comp
L C C1
U 1 1 545649BB
P 850 3300
F 0 "C1" H 850 3400 40  0000 L CNN
F 1 "10u" H 856 3215 40  0000 L CNN
F 2 "~" H 888 3150 30  0000 C CNN
F 3 "~" H 850 3300 60  0000 C CNN
	1    850  3300
	0    -1   -1   0   
$EndComp
$Comp
L R R15
U 1 1 54564A38
P 1400 6650
F 0 "R15" V 1480 6650 40  0000 C CNN
F 1 "2M2" V 1407 6651 40  0000 C CNN
F 2 "~" V 1330 6650 30  0000 C CNN
F 3 "~" H 1400 6650 30  0000 C CNN
	1    1400 6650
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR10
U 1 1 54564ADE
P 1400 6900
F 0 "#PWR10" H 1400 6900 30  0001 C CNN
F 1 "GND" H 1400 6830 30  0001 C CNN
F 2 "" H 1400 6900 60  0000 C CNN
F 3 "" H 1400 6900 60  0000 C CNN
	1    1400 6900
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 54564AE4
P 5450 7000
F 0 "R16" V 5530 7000 40  0000 C CNN
F 1 "10k" V 5457 7001 40  0000 C CNN
F 2 "~" V 5380 7000 30  0000 C CNN
F 3 "~" H 5450 7000 30  0000 C CNN
	1    5450 7000
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR20
U 1 1 54564AEA
P 5450 7250
F 0 "#PWR20" H 5450 7250 30  0001 C CNN
F 1 "GND" H 5450 7180 30  0001 C CNN
F 2 "" H 5450 7250 60  0000 C CNN
F 3 "" H 5450 7250 60  0000 C CNN
	1    5450 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 1800 4600 1800
Wire Wire Line
	3450 1900 4600 1900
Wire Wire Line
	3450 2200 4200 2200
Wire Wire Line
	3450 2300 4300 2300
Wire Wire Line
	650  1500 650  1750
Wire Wire Line
	6250 2650 6250 2800
Wire Wire Line
	6250 1400 6950 1400
Wire Wire Line
	6250 1500 6650 1500
Wire Wire Line
	6250 1600 6250 1700
Wire Wire Line
	6400 1900 6400 1700
Wire Wire Line
	6400 1700 6250 1700
Wire Wire Line
	6250 2100 6750 2100
Wire Wire Line
	6250 2500 6750 2500
Wire Wire Line
	6250 2500 6250 2200
Wire Wire Line
	6750 2500 6750 2550
Wire Wire Line
	6850 1900 6850 1950
Wire Wire Line
	6400 1900 6950 1900
Wire Wire Line
	6250 2700 6550 2700
Wire Wire Line
	6250 3100 6550 3100
Wire Wire Line
	6550 3100 6550 3150
Wire Wire Line
	6250 2900 6250 3100
Connection ~ 6250 3000
Connection ~ 6650 1900
Connection ~ 6250 2700
Wire Wire Line
	1050 1350 1050 1500
Wire Wire Line
	1050 3650 1050 3550
Wire Wire Line
	1050 3550 650  3550
Wire Wire Line
	650  3550 650  3300
Wire Wire Line
	1050 2950 1050 3050
Wire Wire Line
	650  2950 1050 2950
Wire Wire Line
	650  2950 650  2700
Wire Wire Line
	1050 2600 1050 2700
Wire Wire Line
	1050 2000 1050 2100
Wire Wire Line
	650  2350 650  2100
Wire Wire Line
	900  2350 900  2450
Wire Wire Line
	650  2350 1050 2350
Wire Wire Line
	650  1750 1050 1750
Wire Wire Line
	850  1850 850  1750
Connection ~ 850  1750
Wire Wire Line
	6750 2100 6750 2000
Wire Wire Line
	6750 2000 6250 2000
Connection ~ 6750 2100
Connection ~ 6400 2500
Wire Wire Line
	6450 1550 6450 1500
Connection ~ 6450 1500
Connection ~ 6400 2100
Connection ~ 6550 2100
Connection ~ 900  2350
Wire Wire Line
	3450 2100 4100 2100
Wire Wire Line
	4600 1500 4450 1500
Wire Wire Line
	4450 1500 4450 1150
Wire Wire Line
	4450 1150 3450 1150
Wire Wire Line
	3450 1150 3450 1500
Wire Wire Line
	3450 1600 3550 1600
Wire Wire Line
	3550 1600 3550 1250
Wire Wire Line
	3550 1250 4350 1250
Wire Wire Line
	4350 1250 4350 1600
Wire Wire Line
	4350 1600 4600 1600
Wire Wire Line
	3450 1700 4600 1700
Wire Wire Line
	4200 1500 4200 1700
Connection ~ 4200 1700
Connection ~ 6850 1900
Wire Wire Line
	6950 1400 6950 1500
Wire Wire Line
	9050 6250 9050 6100
Wire Wire Line
	8300 5800 8650 5800
Wire Wire Line
	8850 5400 8650 5400
Wire Wire Line
	8650 5400 8650 5800
Wire Wire Line
	9250 5400 9450 5400
Wire Wire Line
	9450 5400 9450 5800
Wire Wire Line
	9650 6250 9650 6200
Wire Wire Line
	9450 5800 9900 5800
Wire Wire Line
	8500 6250 8500 6200
Wire Wire Line
	7900 6250 7900 6000
Connection ~ 9650 5800
Connection ~ 8500 5800
Wire Wire Line
	9050 6100 8950 6100
Wire Wire Line
	8400 5650 8400 5800
Connection ~ 8400 5800
Wire Wire Line
	2750 5900 2750 6050
Wire Wire Line
	1150 6700 1150 6600
Wire Wire Line
	4600 2700 4400 2700
Wire Wire Line
	4600 3000 4450 3000
Wire Wire Line
	5700 6950 5700 7050
Wire Wire Line
	3450 3200 3550 3200
Wire Wire Line
	1050 4450 900  4450
Wire Wire Line
	8500 2500 8300 2500
Wire Wire Line
	8500 2300 8300 2300
Wire Wire Line
	8500 2600 8500 2700
Wire Wire Line
	8500 2400 8500 2300
Wire Wire Line
	6150 4100 6150 4600
Wire Wire Line
	4750 4800 4750 4900
Connection ~ 6150 4500
Wire Wire Line
	4750 4700 4200 4700
Wire Wire Line
	4600 4600 4750 4600
Wire Wire Line
	4750 4500 4600 4500
Wire Wire Line
	4600 4500 4600 4300
Wire Wire Line
	4600 4300 4500 4300
Wire Wire Line
	6150 4800 6300 4800
Wire Wire Line
	6300 4600 6250 4600
Wire Wire Line
	6250 4600 6250 4700
Wire Wire Line
	6250 4700 6150 4700
Wire Wire Line
	6550 4250 6550 4350
Connection ~ 6150 4250
Wire Wire Line
	3450 4400 3550 4400
Wire Wire Line
	3550 4400 3550 4300
Wire Wire Line
	3550 4300 3600 4300
Wire Wire Line
	3450 4500 3600 4500
Wire Wire Line
	9600 3500 9500 3500
Wire Wire Line
	8750 3500 8650 3500
Connection ~ 7800 3500
Wire Wire Line
	7800 3500 7900 3500
Wire Wire Line
	3450 3100 3600 3100
Wire Wire Line
	3650 3300 3550 3300
Wire Wire Line
	3550 3300 3550 3200
Wire Wire Line
	3750 3500 3650 3500
Wire Wire Line
	3650 3500 3650 3400
Wire Wire Line
	3650 3400 3450 3400
Wire Wire Line
	3750 3650 3600 3650
Wire Wire Line
	3600 3650 3600 3500
Wire Wire Line
	3600 3500 3450 3500
Wire Wire Line
	3750 3800 3550 3800
Wire Wire Line
	3550 3800 3550 3600
Wire Wire Line
	3550 3600 3450 3600
Wire Wire Line
	3600 2700 3450 2700
Wire Wire Line
	7450 3800 7600 3800
Wire Wire Line
	7600 3800 7600 3900
Wire Wire Line
	7600 5000 7600 5100
Wire Wire Line
	8300 1550 8300 1600
Wire Wire Line
	8200 1800 8400 1800
Wire Wire Line
	8400 1800 8400 1650
Wire Wire Line
	8200 2000 8500 2000
Wire Wire Line
	4300 2300 4300 2200
Wire Wire Line
	4300 2200 4600 2200
Wire Wire Line
	4200 2200 4200 2100
Wire Wire Line
	4200 2100 4600 2100
Wire Wire Line
	4100 2100 4100 2000
Wire Wire Line
	4100 2000 4600 2000
Wire Wire Line
	1150 6400 1400 6400
Wire Wire Line
	5450 6750 5700 6750
NoConn ~ 3450 4600
NoConn ~ 1050 5000
Wire Wire Line
	3750 3950 3600 3950
Wire Wire Line
	3600 3950 3600 3900
Wire Wire Line
	3600 3900 3450 3900
Wire Wire Line
	3750 4100 3500 4100
Wire Wire Line
	3500 4100 3500 4000
Wire Wire Line
	3500 4000 3450 4000
$Comp
L JFET_N Q1
U 1 1 5467A6A3
P 2600 6400
F 0 "Q1" H 2503 6650 70  0000 C CNN
F 1 "JFET_N" H 2453 6153 60  0000 C CNN
F 2 "~" H 2600 6400 60  0000 C CNN
F 3 "~" H 2600 6400 60  0000 C CNN
	1    2600 6400
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P1
U 1 1 546A70C6
P 7550 5900
F 0 "P1" V 7500 5900 40  0000 C CNN
F 1 "DC In" V 7600 5900 40  0000 C CNN
F 2 "" H 7550 5900 60  0000 C CNN
F 3 "" H 7550 5900 60  0000 C CNN
	1    7550 5900
	-1   0    0    1   
$EndComp
$Comp
L CONN_2 P3
U 1 1 546A7130
P 6050 6850
F 0 "P3" V 6000 6850 40  0000 C CNN
F 1 "Out" V 6100 6850 40  0000 C CNN
F 2 "" H 6050 6850 60  0000 C CNN
F 3 "" H 6050 6850 60  0000 C CNN
	1    6050 6850
	1    0    0    1   
$EndComp
$Comp
L CONN_2 P2
U 1 1 546A7155
P 800 6500
F 0 "P2" V 750 6500 40  0000 C CNN
F 1 "In" V 850 6500 40  0000 C CNN
F 2 "" H 800 6500 60  0000 C CNN
F 3 "" H 800 6500 60  0000 C CNN
	1    800  6500
	-1   0    0    1   
$EndComp
$Comp
L CONN_5 P5
U 1 1 546A7277
P 8900 1550
F 0 "P5" V 8850 1550 50  0000 C CNN
F 1 "ICSP" V 8950 1550 50  0000 C CNN
F 2 "" H 8900 1550 60  0000 C CNN
F 3 "" H 8900 1550 60  0000 C CNN
	1    8900 1550
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K1
U 1 1 546A729E
P 8850 2500
F 0 "K1" V 8800 2500 50  0000 C CNN
F 1 "UART" V 8900 2500 40  0000 C CNN
F 2 "" H 8850 2500 60  0000 C CNN
F 3 "" H 8850 2500 60  0000 C CNN
	1    8850 2500
	1    0    0    1   
$EndComp
NoConn ~ 8500 1450
Wire Wire Line
	8500 1350 8200 1350
Wire Wire Line
	8500 1550 8300 1550
Wire Wire Line
	8400 1650 8500 1650
Wire Wire Line
	8500 2000 8500 1750
$EndSCHEMATC
