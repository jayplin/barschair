EESchema Schematic File Version 2
LIBS:ESP8266
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
LIBS:ESP_Breakout-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP-12E U1
U 1 1 5BD496BF
P 5350 3250
F 0 "U1" H 5350 3150 50  0000 C CNN
F 1 "ESP-12E" H 5350 3350 50  0000 C CNN
F 2 "ESP8266:ESP-12E_SMD" H 5350 3250 50  0001 C CNN
F 3 "" H 5350 3250 50  0001 C CNN
	1    5350 3250
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x11_Male J2
U 1 1 5BD4A960
P 7150 3350
F 0 "J2" H 7150 3950 50  0000 C CNN
F 1 "Conn_01x11_Male" H 7150 2750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x11_Pitch2.54mm" H 7150 3350 50  0001 C CNN
F 3 "" H 7150 3350 50  0001 C CNN
	1    7150 3350
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x11_Male J1
U 1 1 5BD4A99D
P 3550 3350
F 0 "J1" H 3550 3950 50  0000 C CNN
F 1 "Conn_01x11_Male" H 3550 2750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x11_Pitch2.54mm" H 3550 3350 50  0001 C CNN
F 3 "" H 3550 3350 50  0001 C CNN
	1    3550 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2850 4450 2950
Wire Wire Line
	3750 2950 4450 3050
Wire Wire Line
	3750 3050 4450 3150
Wire Wire Line
	3750 3150 4450 3250
Wire Wire Line
	3750 3250 4450 3350
Wire Wire Line
	3750 3350 4450 3450
Wire Wire Line
	3750 3450 4450 3550
Wire Wire Line
	3750 3550 4450 3650
Wire Wire Line
	5100 4150 3750 3650
Wire Wire Line
	3750 3750 5200 4150
Wire Wire Line
	5300 4150 3750 3850
Wire Wire Line
	6250 2950 6950 2850
Wire Wire Line
	6250 3050 6950 2950
Wire Wire Line
	6250 3150 6950 3050
Wire Wire Line
	6250 3250 6950 3150
Wire Wire Line
	6250 3350 6950 3250
Wire Wire Line
	6250 3450 6950 3350
Wire Wire Line
	6250 3550 6950 3450
Wire Wire Line
	6250 3650 6950 3550
Wire Wire Line
	6950 3650 5600 4150
Wire Wire Line
	6950 3750 5500 4150
Wire Wire Line
	6950 3850 5400 4150
$EndSCHEMATC
