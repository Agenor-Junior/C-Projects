/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  :    Agenor Dionizio da Silva Junior
Student ID#:    NRB
Email      :    adionizio-da-silva-j@myseneca.ca
Section    :

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    
    int cent, subCentGen, taxCentGen, totalCentGen;
    int moduleT, moduleL, moduleQ, moduleD, moduleN, moduleP, tValue, tValueTax;
    double subtotalGen, taxesGen, totalGen, average, averPlusTax;
    const int toonies = 200, loonies = 100, quarters = 25,
        dimes = 10, nickels = 5, pennies = 1;
    const double TAX = 0.13;

    //--------------------------------------------------------------PATTY'S VARIABLES
    const char patSize = 'S';
    int shirtS, qttPat, subCentPat, taxCentPat, totalCentPat;
    double shirtSprice, subtotalPat, taxesPat, totalPat;

    //--------------------------------------------------------------SALLY'S VARIABLES
    int shirtM, qttSal, subCentSal, taxCentSal, totalCentSal;
    double shirtMprice, subtotalSal, taxesSal, totalSal;
    const char salSize = 'M';

    //--------------------------------------------------------------TOMMY'S VARIABLES
    int shirtL, qttTom, subCentTom, taxCentTom, totalCentTom;
    double shirtLprice, subtotalTom, taxesTom, totalTom;
    const char tomSize = 'L';

    //=====================================================================START HERE
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%d.%d", &shirtS, &cent);
    shirtS = (shirtS * 100) + cent;
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%d.%d", &shirtM, &cent);
    shirtM = (shirtM * 100) + cent;
    printf("Enter the price for a LARGE shirt: $");
    scanf("%d.%d", &shirtL, &cent);
    shirtL = (shirtL * 100) + cent;

    shirtSprice = (double)shirtS / 100;
    shirtMprice = (double)shirtM / 100;
    shirtLprice = (double)shirtL / 100;

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", shirtSprice);
    printf("MEDIUM : $%.2lf\n", shirtMprice);
    printf("LARGE  : $%.2lf\n", shirtLprice);

    printf("\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &qttPat);

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &qttTom);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &qttSal);

    //-------------------------------------------CONVERTING VALUES IN CENTS AND ROUND

    subCentPat = (int)((shirtSprice * qttPat) * 100 + 0.5);
    subtotalPat = (double)subCentPat / 100;
    taxCentPat = (int)((subtotalPat * TAX) * 100 + 0.5);
    taxesPat = (double)taxCentPat / 100;
    totalCentPat = (int)((subtotalPat + taxesPat) * 100 + 0.5);
    totalPat = (double)totalCentPat / 100;

    subCentSal = (int)((shirtMprice * qttSal) * 100 + 0.5);
    subtotalSal = (double)subCentSal / 100;
    taxCentSal = (int)((subtotalSal * TAX) * 100 + 0.5);
    taxesSal = (double)taxCentSal / 100;
    totalCentSal = (int)((subtotalSal + taxesSal) * 100 + 0.5);
    totalSal = (double)totalCentSal / 100;

    subCentTom = (int)((shirtLprice * qttTom) * 100 + 0.5);
    subtotalTom = (double)subCentTom / 100;
    taxCentTom = (int)((subtotalTom * TAX) * 100 + 0.5);
    taxesTom = (double)taxCentTom / 100;
    totalCentTom = (int)((subtotalTom + taxesTom) * 100 + 0.5);
    totalTom = (double)totalCentTom / 100;

    subCentGen = (int)((subtotalPat + subtotalSal + subtotalTom) * 100 + 0.5);
    subtotalGen = (double)subCentGen / 100;
    taxCentGen = (int)(((subtotalPat + subtotalSal + subtotalTom) * TAX) * 100 + 0.5);
    taxesGen = (double)taxCentGen / 100;
    totalCentGen = (int)((subtotalGen + taxesGen) * 100 + 0.5);
    totalGen = (double)totalCentGen / 100;

    //--------------------------------------------------------------------------TABLE   

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
            patSize, shirtSprice, qttPat, subtotalPat, taxesPat, totalPat);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
            salSize, shirtMprice, qttSal, subtotalSal, taxesSal, totalSal);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
            tomSize, shirtLprice, qttTom, subtotalTom, taxesTom, totalTom);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                        %9.4lf %9.4lf %9.4lf\n\n", 
        subtotalGen, taxesGen, totalGen);

    //-------------------------------------------------CALCULATING COINS BEFORE TAXES

    tValue = (int)(subtotalGen * 100);
    moduleT = tValue % toonies;
    moduleL = moduleT % loonies;
    moduleQ = moduleL % quarters;
    moduleD = moduleQ % dimes;
    moduleN = moduleD % nickels;
    moduleP = moduleN % pennies;
    average = subtotalGen / (qttPat + qttSal + qttTom);

    //----------------------------------------------------TABLE OF COINS BEFORE TAXES

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("             %9.4lf\n",subtotalGen);
    printf("Toonies  %3d %9.4lf\n", tValue / toonies, (double) moduleT / 100);
    printf("Loonies  %3d %9.4lf\n", moduleT / loonies, (double)moduleL / 100);
    printf("Quarters %3d %9.4lf\n", moduleL / quarters, (double)moduleQ / 100);
    printf("Dimes    %3d %9.4lf\n", moduleQ / dimes, (double)moduleD / 100);
    printf("Nickels  %3d %9.4lf\n", moduleD / nickels, (double)moduleN / 100);
    printf("Pennies  %3d %9.4lf\n", moduleN / pennies, (double)moduleP / 100);

    printf("\nAverage cost/shirt: $%.4lf\n\n", average);

    //--------------------------------------------------CALCULATING COINS AFTER TAXES

    tValueTax = (int)(totalGen * 100);
    moduleT =tValueTax % toonies;
    moduleL = moduleT % loonies;
    moduleQ = moduleL % quarters;
    moduleD = moduleQ % dimes;
    moduleN = moduleD % nickels;
    moduleP = moduleN % pennies;
    averPlusTax = totalGen / (qttPat + qttSal + qttTom);
    
    //-----------------------------------------------------TABLE OF COINS AFTER TAXES

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("             %9.4lf\n", totalGen);
    printf("Toonies  %3d %9.4lf\n", tValueTax / toonies, (double)moduleT / 100);
    printf("Loonies  %3d %9.4lf\n", moduleT / loonies, (double)moduleL / 100);
    printf("Quarters %3d %9.4lf\n", moduleL / quarters, (double)moduleQ / 100);
    printf("Dimes    %3d %9.4lf\n", moduleQ / dimes, (double)moduleD / 100);
    printf("Nickels  %3d %9.4lf\n", moduleD / nickels, (double)moduleN / 100);
    printf("Pennies  %3d %9.4lf\n", moduleN / pennies, (double)moduleP / 100);

    printf("\nAverage cost/shirt: $%.4lf\n", averPlusTax);
   
    return 0;
}
