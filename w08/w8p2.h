#pragma once
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
#define MAX_NUM_PRODUCTS 3
#define GRAMS_SUGGEST 64
#define CONVERT_LBSKG  2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
     int idNumber[MAX_NUM_PRODUCTS];
     double price[MAX_NUM_PRODUCTS];
     int calories[MAX_NUM_PRODUCTS];
    double weight[MAX_NUM_PRODUCTS];
};

struct ReportData
{
          int idNumber[MAX_NUM_PRODUCTS];
          double price[MAX_NUM_PRODUCTS];
          int calories[MAX_NUM_PRODUCTS];
      double weightLbs[MAX_NUM_PRODUCTS];
       double weightKG[MAX_NUM_PRODUCTS];
         int weightGrm[MAX_NUM_PRODUCTS];
       double servings[MAX_NUM_PRODUCTS];
    double costPerServ[MAX_NUM_PRODUCTS];
    double costCalServ[MAX_NUM_PRODUCTS];
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
void displayCatFoodData(const int idNumber[], const double* price, const double* weight, const int calories[], const int max);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(double* lbs, double* dblA);

// 9. convert lbs: g
int convertLbsG(double* lbs, int* intA);

// 10. convert lbs: kg / g
void convertLbs(double* lbs, double* dblA, int* intB);

// 11. calculate: servings based on gPerServ
double calculateServings(const int weighGram, const int gramsSuggest, double* numServ);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* var1, const double* var2, double* var3);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* var1, const double* var2, double* var3);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapProdct);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct ReportData analysis, int cheapProdct);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);
