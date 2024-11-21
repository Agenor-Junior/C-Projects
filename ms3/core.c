/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :Agenor Dionizio da Silva Junior
Student ID#: 138121223
Email      : adionizio-da-silva-j@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//-------------------------------------------------- 1. FUNCTION INPUT INT
int inputInt(void)
{
    int inputInt;
    char inputChar;
    do
    {
        scanf("%d%c", &inputInt, &inputChar);
        if (inputChar != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (inputChar != '\n');

    return inputInt;
}

//----------------------------------------- 2. FUNCTION INPUT INT POSITIVE
int inputIntPositive(void)
{
    int inputPositive;
    char null = '\n';
    do
    {
        scanf("%d%c", &inputPositive, &null);
        if (null != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (inputPositive <= 0)
        {
            printf("ERROR! Value must be > 0: ");

        }
    } while (null != '\n' || inputPositive <= 0);

    return inputPositive;
}

//-------------------------------------------- 3. FUNCTION INPUT INT RANGE
int inputIntRange(int lowerRange, int upperRange)
{
    int intValue;
    char null;
    do
    {
        scanf("%d%c", &intValue, &null);
        if (null != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (intValue<lowerRange || intValue>upperRange)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerRange, upperRange);
        }
    } while (null != '\n' || intValue < lowerRange || intValue > upperRange);

    return intValue;
}

//------------------------------------------ 4. FUNCTION INPUT CHAR OPTION
char inputCharOption(const char * charOption)
{
    char charInput;
    int i, j = 0;
    do
    {
        scanf(" %c", &charInput);
        for (i = 0; charOption[i] != '\0'; i++)
        {
            if (charInput == charOption[i])
            {
                j++;
            }
        }

        if (j == 0)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", charOption);
        }
    } while (j == 0);
    return charInput;
}

//----------------------------------------- 5. FUNCTION INPUT STRING VALUE
void inputCString(char* stringValue, int min, int max)
{
    int lengthString = 0, i = 1;
    char stringInput[50];

    do
    {
        scanf(" %[^\n]", stringInput);       
        lengthString = strlen(stringInput);
        
        if (lengthString >= min && lengthString <= max)
        {
            i = 0;
            strcpy(stringValue, stringInput);
        }

        else
        {
            if (min == max)
            {
                printf("Invalid 10-digit number! Number: ");
            }
            else if (lengthString > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
    } while (i);
}

//----------------------------------- 6. FUNCTION DISPLAY FORMATTED NUMBER
void displayFormattedPhone(const char* telNumber)
{
    int i = 0, lengthTel = 0, digit = 0;
    if (telNumber == NULL)
    {
        printf("(___)___-____");
    }

    else
    {
        lengthTel = strlen(telNumber); 
        for (i = 0; telNumber[i] != '\0'; i++)
        {
            if (telNumber[i] >= '0' && telNumber[i] <= '9')
            {
                digit++;
            }            
        }

        if (lengthTel == 10 && digit == 10)
        {
            printf("(");

            for (i = 0; i < 3; i++)
            {
                printf("%c", telNumber[i]);
            }

            printf(")");

            for (i = 3; i < 10; i++)
            {
                printf("%c", telNumber[i]);
                if (i == 5)
                {
                    printf("-");
                }
            }
        }
        else { printf("(___)___-____"); }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////