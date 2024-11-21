#pragma once
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

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// MS#3 Additional macro's:
#define START_HOUR 10
#define END_HOUR 14
#define MINUTE_INTERVAL 30

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////
// 
//-------------------------------------------------- 1. FUNCTION INPUT INT
int inputInt(void);

//----------------------------------------- 2. FUNCTION INPUT INT POSITIVE
int inputIntPositive(void);

//-------------------------------------------- 3. FUNCTION INPUT INT RANGE
int inputIntRange(int lowerRange, int upperRange);

//------------------------------------------ 4. FUNCTION INPUT CHAR OPTION
char inputCharOption(const char* charOption);

//----------------------------------------- 5. FUNCTION INPUT STRING VALUE
void inputCString(char* stringValue, int min, int max);

//----------------------------------- 6. FUNCTION DISPLAY FORMATTED NUMBER
void displayFormattedPhone(const char* telNumber);

//////////////////////////////////////
// UTILITY FUNCTION
//////////////////////////////////////

#endif // !CORE_H