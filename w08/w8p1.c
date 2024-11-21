/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : Agenor Dionizio da Silva Junior
Student ID#: 138121223
Email      : adionizio-da-silva-j@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// System Libraries
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intA)
{
    int positInt = 0, i = 0;
    int intValues[ENTRIES] = { 0 };

    do 
    {
        scanf("%d", &intValues[i]);

        if (intValues[i] < 1) 
        {
            printf("ERROR: Enter a positive value: ");
        }

        else
        {
            positInt = intValues[i];

            if (intA != NULL)
            {
                *intA = positInt;
            }

            return positInt;
        }
        i++;
    } while (intValues[i - 1] < 1);

    return positInt;
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dblA)
{	
    double positDouble=0;
    int i = 0;
    double doublevalues[ENTRIES] = { 0 };

    do {
        scanf("%lf", &doublevalues[i]);

        if (doublevalues[i] < 1) 
        {
            printf("ERROR: Enter a positive value: ");
        }

        else
        {
            positDouble = doublevalues[i];

            if (dblA != NULL)
            {
                *dblA = positDouble;
            }
            return positDouble;
        }
        i++;
    } while (doublevalues[i - 1] < 1);

    return positDouble;    
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int maxProducts, const int gramsSuggest)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", maxProducts);
    printf("NOTE: A 'serving' is %dg\n\n", gramsSuggest);   
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numProducts) 
{
    struct CatFoodInfo info = { {0}, {0.0}, {0}, {0.0} };
    int i, getvalue = 0;

    for (i = 0; i < numProducts; i++) 
    {
        printf("Cat Food Product #%d\n", i + 1);
        printf("--------------------\n");
        printf("SKU           : ");
        info.idNumber[i] = getIntPositive(&getvalue);

        printf("PRICE         : $");
        info.price[i] = getDoublePositive(NULL);

        printf("WEIGHT (LBS)  : ");
        info.weight[i] = getDoublePositive(NULL);

        printf("CALORIES/SERV.: ");
        info.calories[i] = getIntPositive(&getvalue);
        printf("\n");
    }

    return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int idNumber[], double* price, double* weight, int calories[], int max)
{   
    int i;
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
    
    for (i = 0; i < max; i++)
    {
        printf("%07d %10.2lf %10.1lf %8d\n", idNumber[i], price[i], weight[i], calories[i]);
    }
}

// 7. Logic entry point
void start()
{   
    struct CatFoodInfo catInfo;
    openingMessage(MAX_NUM_PRODUCTS, GRAMS_SUGGEST);
    catInfo = getCatFoodInfo(MAX_NUM_PRODUCTS);
    displayCatFoodData(catInfo.idNumber, catInfo.price, catInfo.weight, catInfo.calories, MAX_NUM_PRODUCTS);
}