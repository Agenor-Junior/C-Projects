#pragma once
/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Agenor Dionizio da SIlva Junior
Student ID#: 138121223
Email      : adionizio-da-silva-j@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

//-------------------------------------------------- CLEAR INPUT BUFFER
void clearInputBuffer(void);

//-------------------------------------------------------- VOID SUSPEND
void suspend(void);

//-------------------------------------------------- FUNCTION INPUT INT
int inputInt(void);

//----------------------------------------- FUNCTION INPUT INT POSITIVE
int inputIntPositive(void);

//-------------------------------------------- FUNCTION INPUT INT RANGE
int inputIntRange(int lowerRange, int upperRange);

//------------------------------------------ FUNCTION INPUT CHAR OPTION
char inputCharOption(const char* charList);

//----------------------------------------- FUNCTION INPUT STRING VALUE
void inputCString(char* stringValue, int min, int max);

//----------------------------------- FUNCTION DISPLAY FORMATTED NUMBER
void displayFormattedPhone(const char* telNumber);
