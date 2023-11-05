/**
 * @file Spi.c
 * @author Rohan GB
 * @date 13 April 2023
 * @brief This file is for Spi  Pheripheral Testing
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Spi.h"
char Spi_content[1000]; 
int id_no=0xFFAA;

/**
 * @brief This function is for Spi write
 * This function write content and stores in Spi_content
 * This Function also collects the id
 * @return This functon returns 0 if init is successfull
*/


int Spi_write()
{   time_t t;
    struct tm *timestamp;


    t=time(NULL);
    timestamp=localtime(&t);

    printf("write here:");
    fflush(stdin);
    fgets(Spi_content, 1000, stdin);

    //time format
    char timestamp_str[100];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S",timestamp);

    FILE *Spi_file_content;
    Spi_file_content=fopen("Spi_file.txt","a");
    if (Spi_file_content== NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    
    fprintf(Spi_file_content,"[%s]  |%s\n",timestamp_str,Spi_content);
    printf("written succesfully\n");
    fclose(Spi_file_content);
    return 0;
} 


/**
 * @brief This function is for Spi read
 * This function display the content in Spi_content
 * If Spi_content is empty gives Null result
 * @return it does not return
*/

int Spi_read()
{
    if (Spi_content[0] == '\0'){
        printf("spi is empty\n");
        return -1;
    }
    else{
        printf(Spi_content,"\n");
        return 0;
        }
}

/**
 * @brief This function is for Spi_read_manufactureID
 * This function display the id
 * If id is empty gives Null result
 * @return This functon returns 0 if init is successfull, otherwise it returns -1
*/
int Spi_read_manufactureID()
{
    printf("The Manufacture ID:%02X\n", id_no);
    return 0;
}

/**
 * @brief This is main function for Spi
 * This function switches Spi_write,Spi_read,Spi_read_manufactureID
 * @return This functon returns 0 if init is successfull
*/

int Spi()
{
unsigned int choice = 0;

printf("\nChoose operation to perform on SPI\n\n");
printf("1. Spi_write\n");
printf("2. Spi_read\n");
printf("3. Spi_read_manufactureID\n");
printf("4. Exit\n");

while (choice != 4) {
    printf("Enter your choice: ");
    scanf("%u", &choice);

    switch (choice)
    {
        case 1:
            Spi_write();
            break;
        case 2:
            Spi_read();
            break;
        case 3:
            Spi_read_manufactureID();
            break;
        case 4:
            printf("Exiting SPI operations...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

    return 0;
}
