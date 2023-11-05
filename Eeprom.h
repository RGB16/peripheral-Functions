/**
 * @file Eeprom.h
 *@brief This file is for Uart  Pheripheral Testing header file
 * @date 13 April 2023
 */


#include <stdio.h>
#include <string.h>

char Eeprom_content[1000];

int Eeprom_write();
int Eeprom_read();
int Eeprom_erase();
int Eeprom();