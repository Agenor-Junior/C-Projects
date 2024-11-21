/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
Full Name  : Agenor Dionizio da SIlva Junior	
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
#include "w8p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intA)
{
    int positInt = 0, i = 0;
    int intValues[MAX_NUM_PRODUCTS] = { 0 };

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
    double positDouble = 0;
    int i = 0;
    double doublevalues[MAX_NUM_PRODUCTS] = { 0 };

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
void displayCatFoodData(const int idNumber[],const double* price, const double* weight, const int calories[], const int max)
{
    int i;
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");

    for (i = 0; i < max; i++)
    {
        printf("%07d %10.2lf %10.1lf %8d\n", idNumber[i], price[i], weight[i], calories[i]);
    }
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg (double* lbs, double* dblA)
{
    double kilogram = 0;
    kilogram = *lbs / 2.20462;

    if (dblA != NULL)
    {
        *dblA = kilogram;
    }
    return kilogram;   
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG (double* lbs, int* intA)
{
    int grams;
    grams = (int) (convertLbsKg(lbs, NULL) * 1000);

    if (intA != NULL)
    {
        *intA = grams;
    }
    return grams;    
}

// 10. convert lbs: kg and g
void convertLbs(double* lbs, double* dblA, int *intB)
{    
    double kilogram = convertLbsKg (lbs, dblA);
    int grams = convertLbsG (lbs, intB);
    *dblA = kilogram;
    *intB = grams;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int weighGram, const int gramsSuggest, double* numServ)
{
    double servings, gramInDouble;
    gramInDouble = (double)weighGram;
    servings = (gramInDouble / gramsSuggest);

    if (numServ != NULL)
    {
        *numServ = servings;
    }
   return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* servings, double* costServ)
{
    double costServings;
    costServings = *price / *servings;

    if (costServ != NULL)
    {
        *costServ = costServings;
    }
    return costServings;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* costPerServ, const double* calories, double* costCal)
{
    double costCalories;
    costCalories = *costPerServ / *calories;

    if (costCal != NULL)
    {
        *costCal = costCalories;
    }
    return costCalories;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catInfo)
{
    struct ReportData calculateData;
    int i;
    double numServ = 0, costServ = 0, costCal = 0;
    double caloriesAsDouble;

    for (i = 0; i < MAX_NUM_PRODUCTS; i++)
    {
        calculateData.idNumber[i] = catInfo.idNumber[i];
        calculateData.price[i] = catInfo.price[i];
        calculateData.weightLbs[i] = catInfo.weight[i];
        calculateData.calories[i] = catInfo.calories[i];
        calculateData.weightKG[i] = convertLbsKg(&calculateData.weightLbs[i], NULL);
        calculateData.weightGrm[i] = convertLbsG(&calculateData.weightLbs[i], NULL);
        calculateData.servings[i] = calculateServings(calculateData.weightGrm[i], GRAMS_SUGGEST, &numServ);
        calculateData.costPerServ[i] = calculateCostPerServing(&calculateData.price[i], &calculateData.servings[i], &costServ);
        caloriesAsDouble = (double)calculateData.calories[i];
        calculateData.costCalServ[i] = calculateCostPerCal(&calculateData.costPerServ[i],&caloriesAsDouble, &costCal);
    }
    return calculateData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	//printf("Analysis Report (Note: Serving = %dg\n", ? ? ? );
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int lowerIndex)
{
    int i;

    for (i = 0; i < MAX_NUM_PRODUCTS; i++)
    {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
                report.idNumber[i], report.price[i], report.weightLbs[i], report.weightKG[i], report.weightGrm[i], 
                report.calories[i], report.servings[i], report.costPerServ[i], report.costCalServ[i]);

        lowerIndex == i ? printf(" ***\n") : printf("\n");
    }
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct ReportData analysis, int cheapProdct)
{
    printf("\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n", analysis.idNumber[cheapProdct], analysis.price[cheapProdct]);
    printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    int i, lowerIndex=0;
    double lowerValue;
    struct CatFoodInfo catInfo;
    struct ReportData report;
    openingMessage(MAX_NUM_PRODUCTS, GRAMS_SUGGEST);
    catInfo = getCatFoodInfo(MAX_NUM_PRODUCTS);
    displayCatFoodData(catInfo.idNumber, catInfo.price, catInfo.weight, catInfo.calories, MAX_NUM_PRODUCTS);
    printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAMS_SUGGEST);
    report = calculateReportData(catInfo);

    lowerValue = report.costPerServ[0];
    for (i = 1; i < MAX_NUM_PRODUCTS; i++)
    {
        if (report.costPerServ[i] < lowerValue)
        {
            lowerIndex = i;
            lowerValue = report.costPerServ[i];
        }
    }

    displayReportHeader();
    displayReportData(report, lowerIndex);
    displayFinalAnalysis(report, lowerIndex);
}
