/**
 * @file Eeprom.c
 * @author Rohan GB
 * @date 13 April 2023
 * @brief This file is for Eeprom  Pheripheral Testing
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

char Eeprom_content[1000];

/**
 * @brief This function is for Eeprom write
 * This function write content and stores in Eeprom_content and Eeprom.txt file
 * @return This functon returns 0 if init is successfull,otherwise it returns -1
*/

int Eeprom_write() {
    time_t t;
    struct tm *timestamp;
    char Eeprom_content[100];

    printf("Write here:\n");
    fflush(stdin);
    fgets(Eeprom_content, sizeof(Eeprom_content), stdin);

    // Get the current time
    t = time(NULL);
    timestamp = localtime(&t);

    FILE *Eeprom_file_content;
    Eeprom_file_content = fopen("Eeprom_file.txt", "a");
    if (Eeprom_file_content == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    // Format the timestamp
    char timestamp_str[100];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S",timestamp);

    // Write the timestamp and content to the file
    fprintf(Eeprom_file_content, "[%s]  |%s\n",timestamp_str, Eeprom_content);
    printf("Text written to EEPROM successfully.\n");
    fclose(Eeprom_file_content);
    return 0;
}

/**
 * @brief This function is for Eeprom read
 * This function display the content in Eeprom_content
 * If Eeprom_content is empty gives Null result
 * @return This functon returns 0 if init is successfull, otherwise it returns -1
*/
int Eeprom_read()
{
    if (Eeprom_content[0] == '\0')
    {
        printf("Eeprom is empty\n");
        return -1;
    }
    else{
        printf("%s",Eeprom_content);

        return 0;
    }
}

/**
 * @brief This function is for Eeprom erase
 * This function delete Eeprom_content value make it Null
 * @return This functon returns 0 if init is successfull, otherwise it returns -1
*/


int Eeprom_erase()
{
    if (Eeprom_content[0] == '\0'){
        printf("Eeprom is empty\n");
        return -1;
    }
    else{
            Eeprom_content[0]='\0'; 
            printf("content is erased\n");
            return 0;
        }
}

/**
 * @brief This is main function for Eeprom 
 * This function switches Eeprom_write,Eeprom_read,Eeprom_erase
 * @return This functon returns 0 if init is successfull
*/


int Eeprom()
{
unsigned int choice = 0;

printf("\nChoose an operation to perform on EEPROM:\n\n");
printf("1. Write to EEPROM\n");
printf("2. Read from EEPROM\n");
printf("3. Erase EEPROM\n");
printf("4. Exit\n");

while (choice != 4) 
{
    printf("Enter your choice: ");
    scanf("%u", &choice);

    switch (choice) 
    {
        case 1:
            Eeprom_write();
            break;
        case 2:
            Eeprom_read();
            break;
        case 3:
            Eeprom_erase();
            break;
        case 4:
            printf("Exiting EEPROM menu...\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            break;
    }
}

    return 0;
}