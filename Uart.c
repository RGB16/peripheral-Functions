/**
 * @file Uart.c
 * @author Rohan GB
 * @date 13 April 2023
 * @brief This file is for Uart  Pheripheral Testing
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

char Uart_content[1000];




/**
 * @brief This function is for Uart write
 * This function write content and stores in Uart_content and Uart_file
 * @return This function returns 0 if init is successfull,otherwise it returns -1
*/


int Uart_write()
{
    time_t t;
    struct tm *timestamp;

    printf("write here:\n");
    fflush(stdin);   
    fgets(Uart_content, 1000, stdin);
 
    t = time(NULL);
    timestamp = localtime(&t);

    FILE *uart_file_content;
    uart_file_content=fopen("uart_file.txt","a");

    char timestamp_str[100];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S",timestamp);

    if (uart_file_content== NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }
    fprintf(uart_file_content,"[%s]  |%s\n",timestamp_str,Uart_content);
    printf("written succesfully\n");
    fclose(uart_file_content);
    return 0;
}


/**
 * @brief This function is for Uart read
 * This function display the content in Uart_content
 * If Uart_content is empty gives Null result
 * @return This functon returns 0 if init is successfull, otherwise it returns -1
*/

int Uart_read()
{
    if (Uart_content[0] == '\0'){
        printf("Uart is empty\n");
        return -1;
    }
    else
    {
        printf("%s", Uart_content);
        return 0;
    }

}

/**
 * @brief This is main function for Uart
 * This function switches Uart_write,Uart_read
 * @return This functon returns 0 if init is successfull
*/



int Uart()
{
    unsigned int choice = 0;

    printf("\nChoose operation to perform on UART\n\n");
    printf("1. Uart_write\n");
    printf("2. Uart_read\n");
    printf("3. Exit\n");

    while (choice != 3) {
        printf("Enter your choice: ");
        scanf("%u", &choice);

        switch (choice)
        {
            case 1:
                Uart_write();
                break;
            case 2:
                Uart_read();
                break;
            case 3:
                printf("Exiting UART operations...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }


    return 0;
}