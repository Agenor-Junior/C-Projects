#pragma once
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Agenor Dionizio da Silva Junior
Student ID#: 198121223
Email      : adionizio-da-silva-j
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define ENTRIES 3
#define MAX_NUM_PRODUCTS 3
#define GRAMS_SUGGEST 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo 
{
    int  idNumber [MAX_NUM_PRODUCTS];
    double  price [MAX_NUM_PRODUCTS];
    int  calories [MAX_NUM_PRODUCTS];
    double weight [MAX_NUM_PRODUCTS];
};


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intA);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dblA);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int maxProducts, const int gramsSuggest);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int maxProducts);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int idNumber[], double* price, double* weight, int calories[], int max);

// 7. Logic entry point
void start();
