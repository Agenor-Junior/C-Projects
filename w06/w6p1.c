#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM_MAX 10

int main(void)
{
    //----------------------------------------------------------------------------------- VARIABLES
    const double minIncome = 500.00, maxIncome = 400000.00;
    const double minCost = 100.00;
    double netIncome, totalCost = 0.0;
    int  i, numItems, index = 0;

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

    printf("\nBest of luck in all your future endeavours!\n\n");

    return 0;
}
