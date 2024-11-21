/*//////////////////////////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Agenor Dionizio da SIlva Junior
Student ID#: 138121223
Email      : adionizio-da-silva-j@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
//////////////////////////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include "core.h"
#include <stdio.h>

//--------------------------------------------------------------------------- CLEAR INPUT BUFFER
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing! 
    }
}

//--------------------------------------------------------------------------------- VOID SUSPEND 
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//--------------------------------------------------------------------------- FUNCTION INPUT INT
int inputInt(void)
{
    int value1Int;  char value1Char;
    do
    {
        scanf("%d%c", &value1Int, &value1Char);
        if (value1Char != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    } while (value1Char != '\n');

    return value1Int;
}

//------------------------------------------------------------------ FUNCTION INPUT INT POSITIVE
int inputIntPositive(void)
{
    int value2Int;   char value2Char;

    do
    {
        scanf("%d%c", &value2Int, &value2Char);
        if (value2Char != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (value2Int <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }

    } while (value2Int <= 0);

    return value2Int;
}

//--------------------------------------------------------------------- FUNCTION INPUT INT RANGE
int inputIntRange(int lowerRange, int upperRange)
{
    int value3Int;  char value3Char;

    do
    {
        do
        {
            scanf("%d%c", &value3Int, &value3Char);
            if (value3Char != '\n')
            {
                clearInputBuffer();
                printf("Error! Input a whole number: ");
            }

        } while (value3Char != '\n');

        if (value3Int<lowerRange || value3Int>upperRange)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerRange, upperRange);
        }

    } while (value3Int<lowerRange || value3Int>upperRange);

    return value3Int;
}

//------------------------------------------------------------------- FUNCTION INPUT CHAR OPTION
char inputCharOption(const char* charList)
{
    char value4Char;  int i, charMatch = 0;

    do
    {
        scanf("%c", &value4Char);
        clearInputBuffer();
        for (i = 0; charList[i] != '\0'; i++)
        {
            if (value4Char == charList[i])
            {
                charMatch = 1;
            }
        }
        if (charMatch == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", charList);
        }

    } while (charMatch == 0);

    return value4Char;
}

//------------------------------------------------------------------ FUNCTION INPUT STRING VALUE
void inputCString(char* stringValue, int min, int max)
{
    int i, counter = 0;  char value[50];

    do
    {
        scanf("%[^\n]", value);
        clearInputBuffer();

        for (i = 0; value[i] != '\0'; i++)
        {
            counter = i + 1;
        }

        if ((counter < min || counter > max) && min == max)
        {
            printf("ERROR: String length must be exactly %d chars: ", max);
        }

        else if (counter < min)
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }

        else if (counter > max)
        {
            printf("ERROR: String length must be no more than %d chars: ", max);
        }

        else { break; }

    } while (counter < min || counter > max);

    for (i = 0; value[i] != '\0'; i++)
    {
        *stringValue = value[i];
        stringValue++;
    }
    *stringValue = '\0';
}

//------------------------------------------------------------ FUNCTION DISPLAY FORMATTED NUMBER
void displayFormattedPhone(const char* telNumber)
{
    int i, counter = 0;

    if (telNumber != NULL)
    {
        for (i = 0; telNumber[i] != '\0'; i++)
        {
            if (telNumber[i] >= '0' && telNumber[i] <= '9')
            {
                counter++;
            }
        }

        if (counter == 10)
        {
            printf("(%c%c%c)", telNumber[0], telNumber[1], telNumber[2]);
            printf("%c%c%c-", telNumber[3], telNumber[4], telNumber[5]);
            printf("%c%c%c%c", telNumber[6], telNumber[7], telNumber[8], telNumber[9]);
        }

        else
        {
            printf("(___)___-____");
        }
    }

    else
    {
        printf("(___)___-____");
    }
}