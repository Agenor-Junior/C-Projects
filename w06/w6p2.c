/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : Agenor Dionizio da Silva Junior
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
#define NUM_MAX 10

int main(void)
{
    //----------------------------------------------------------------------------------- VARIABLES
    const double minIncome = 500.00, maxIncome = 400000.00;
    const double minCost = 100.00, round = 1.0;
    double netIncome, totalCost = 0.0, valueCalc;
    int  i, numItems, index = 0;
    int selection, flag = 0, year = 12, totalMonths, priority;

    double itemCost[NUM_MAX] = { 0.0 };
    int   importance[NUM_MAX] = { 0 };
    char  finOption[NUM_MAX] = { 'y' };

    //================================================================================== START HERE
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    //---------------------------------------------------------------------------- NET INCOME INPUT
    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &netIncome);

        if (netIncome < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }

        else if (netIncome > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }

    } while (netIncome < minIncome || netIncome > maxIncome);

    //------------------------------------------------------------------------------ HOW MANY ITEMS
    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);

        if (numItems < 1 || numItems > NUM_MAX)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }

    } while (numItems < 1 || numItems > NUM_MAX);


    //----------------------------------------------------------------------------- NUMBER OF ITEMS
    for (i = 1; i <= numItems; i++)
    {
        printf("\nItem-%d Details:\n", i);

        //------------------------------------------------------------------------------- ITEM COST
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[index]);

            if (itemCost[index] < minCost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }

        } while (itemCost[index] < minCost);

        //-------------------------------------------------------------------------------- PRIORITY
        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &importance[index]);

            if (importance[index] < 1 || importance[index] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }

        } while (importance[index] < 1 || importance[index] > 3);

        //------------------------------------------------------------------------- FINANCE OPTIONS
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finOption[index]);

            if (finOption[index] != 'y' && finOption[index] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        } while (finOption[index] != 'y' && finOption[index] != 'n');

        index++;
    }

    //---------------------------------------------------------------------------- TABLE OF RESULTS
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    index = 0;

    for (i = 1; i <= numItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i, importance[index], finOption[index], itemCost[index]);
        totalCost = totalCost + itemCost[index];
        index++;
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", totalCost);

    

    //================================================================================ START PART 2
    do
    {
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);

        //--------------------------------------------------------------------SELECTION TO QUIT (0)
        if (selection == 0)
        {
            printf("\nBest of luck in all your future endeavours!\n");
            flag = 1;
        }

        else
        {
            //------------------------------------------------------------ SELECTION ALL INTENS (1)               
            if (selection == 1)
            {
                printf("\n====================================================\n");
                valueCalc = totalCost;
                printf("Filter:   All items\n");
                printf("Amount:   $%.2lf\n", valueCalc);
                totalMonths = (int)((valueCalc / netIncome) + round);
                printf("Forecast: %d years, %d months\n", totalMonths / year, totalMonths % year);                                     
                index = 0;

                for (i = 1; i <= numItems; i++)
                {
                    if (finOption[index] == 'y')
                    {
                        printf("NOTE: Financing options are available on some items.\n");
                        printf("      You can likely reduce the estimated months.\n");
                        i = numItems++;
                    }
                    index++;
                }

                printf("====================================================\n");
            }

            //----------------------------------------------------------- SELECTION BY PRIORITY (2)
            else if (selection == 2)
            {
                do
                {
                    //------------------------------------------------------------- SELECT PRIORITY
                    printf("\nWhat priority do you want to filter by? [1-3]: ");
                    scanf("%d", &priority);
                    printf("\n====================================================\n");
                    printf("Filter:   by priority (%d)\n", priority);                    

                    if (priority < 1 || priority > 3)
                    {
                        printf("      ERROR: Value must be between 1 and 3\n");
                    }

                } while (priority < 1 || priority > 3);

                //--------------------------------------------------------------------- CALCULATION
                valueCalc = 0;
                index = 0;

                for (i = 1; i <= numItems; i++)
                {
                    if (priority == importance[index])
                    {
                        valueCalc = valueCalc + itemCost[index];
                    }
                    index++;
                }

                printf("Amount:   $%.2lf\n", valueCalc);
                totalMonths = (int)((valueCalc / netIncome) + round);
                printf("Forecast: %d years, %d months\n", totalMonths / year, totalMonths % year);

                //------------------------------------------------------------- FINANCING AVAILABLE
                index = 0;
                for (i = 1; i <= numItems; i++)
                {
                    if (priority == importance[index])
                    {
                        if (finOption[index] == 'y')
                        {
                            printf("NOTE: Financing options are available on some items.\n");
                            printf("      You can likely reduce the estimated months.\n");
                            i = numItems++;
                        }
                    }
                    index++;
                }

                printf("====================================================\n");
            }
            
            else
            {
                printf("\nERROR: Invalid menu selection.\n");
            }
        }

    } while (flag == 0);

    return 0;
}
