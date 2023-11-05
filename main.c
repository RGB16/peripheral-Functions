/**
 * @file main.c
 * @date  20 April 2023
 * @brief This file is main function for Eeprom,Uart,Spi Menu_bar
 */


// genric peripharal testing

#include "Eeprom.h"
#include "Spi.h"
#include "Uart.h"

// #include "functions.h"
/**
 * The main function allows the user to select between Eeprom, Uart, and Spi options and continuously
 * iterate until the user chooses to exit.
 * 
 * @return an integer value of 0.
 */

int main()
{
    unsigned int choice;
    char continuee = 'y';
    printf("\n\nWelcome Sir/Madam:\n");
    while (continuee == 'y' || continuee == 'Y') {
        printf("\n\nSelect the below option\n\n\n");
        printf("1. Eeprom\n");
        printf("2. Uart\n");
        printf("3. Spi\n");

        scanf("%u", &choice);

        switch (choice) {
            case 1:
                Eeprom();
                break;
            case 2:
                Uart();
                break;
            case 3:
                Spi();
                break;
            default:
                printf("Invalid choice. Please select a number between 1 and 3.\n");
                break;
        }

        printf("\n\nPress 'y' to continue or any other key to exit.\n\n");
        scanf(" %c", &continuee);
    }


    printf("\nThank you");
    return 0;
}



//gcc main.c functions.c  ,  .\test.exe  run command 
// gcc .\main.c  .\Eeprom.c .\Uart.c .\Spi.c -o 



//gcc -c Eeprom.c Uart.c Spi.c main.c
//gcc Eeprom.o Uart.o Spi.o main.o -o main_program
//./main_program