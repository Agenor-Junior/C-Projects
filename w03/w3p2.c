/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

int main(void)
{
    const double GRAMS_IN_LBS = 453.5924;
    
    //----------------------------------------------------------------------------------------------------- COFFEE 1
    char type1;
    int  weight1;
    char cream1;

    //----------------------------------------------------------------------------------------------------- COFFEE 2
    char type2;
    int  weight2;
    char cream2;

    //----------------------------------------------------------------------------------------------------- COFFEE 3
    char type3;
    int  weight3;
    char cream3;

    //--------------------------------------------------------------------------------------------- USER PREFERENCES
    char uStrenght, uCream;
    int uServings;

    //=================================================================================================== START HERE

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf(" %d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf(" %d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf(" %d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);

    //------------------------------------------------------------------------------------------------------ TABLE 1

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",   type1 == 'l' || type1 == 'L', type1 == 'm' || type1 == 'M', type1 == 'r' || 
                                                                           type1 == 'R', weight1, weight1 / GRAMS_IN_LBS, cream1 == 'y' || cream1 == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",   type2 == 'l' || type2 == 'L', type2 == 'm' || type2 == 'M', type2 == 'r' || 
                                                                           type2 == 'R', weight2, weight2 / GRAMS_IN_LBS, cream2 == 'y' || cream2 == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", type3 == 'l' || type3 == 'L', type3 == 'm' || type3 == 'M', type3 == 'r' || 
                                                                           type3 == 'R', weight3, weight3 / GRAMS_IN_LBS, cream3 == 'y' || cream3 == 'Y');

    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &uStrenght);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &uCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &uServings);

    //------------------------------------------------------------------------------------------------------ TABLE 2

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",   ((uStrenght == 'l' || uStrenght == 'L') && (type1 == 'l' || type1 == 'L')) || ((uStrenght == 'm' || uStrenght == 'M') && (type1 == 'm' || type1 == 'M')) || 
                                                                 ((uStrenght == 'r' || uStrenght == 'R') && (type1 == 'r' || type1 == 'R')), uServings < 5, 
                                                                 ((uCream == 'y' || uCream == 'Y') && (cream1 == 'y' || cream1 == 'Y')) || ((uCream == 'n' || uCream == 'N') && (cream1 == 'n' || cream1 == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n",   ((uStrenght == 'l' || uStrenght == 'L') && (type2 == 'l' || type2 == 'L')) || ((uStrenght == 'm' || uStrenght == 'M') && (type2 == 'm' || type2 == 'M')) || 
                                                                 ((uStrenght == 'r' || uStrenght == 'R') && (type2 == 'r' || type2 == 'R')), uServings >= 5 && uServings < 10, 
                                                                 ((uCream == 'y' || uCream == 'Y') && (cream2 == 'y' || cream2 == 'Y')) || ((uCream == 'n' || uCream == 'N') && (cream2 == 'n' || cream2 == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((uStrenght == 'l' || uStrenght == 'L') && (type3 == 'l' || type3 == 'L')) || ((uStrenght == 'm' || uStrenght == 'M') && (type3 == 'm' || type3 == 'M')) || 
                                                                 ((uStrenght == 'r' || uStrenght == 'R') && (type3 == 'r' || type3 == 'R')), uServings >= 10, 
                                                                 ((uCream == 'y' || uCream == 'Y') && (cream3 == 'y' || cream3 == 'Y')) || ((uCream == 'n' || uCream == 'N') && (cream3 == 'n' || cream3 == 'N')));

    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &uStrenght);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &uCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &uServings);

    //------------------------------------------------------------------------------------------------------ TABLE 3

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",   ((uStrenght == 'l' || uStrenght == 'L') && (type1 == 'l' || type1 == 'L')) || ((uStrenght == 'm' || uStrenght == 'M') && (type1 == 'm' || type1 == 'M')) || 
                                                                 ((uStrenght == 'r' || uStrenght == 'R') && (type1 == 'r' || type1 == 'R')), uServings < 5, 
                                                                 ((uCream == 'y' || uCream == 'Y') && (cream1 == 'y' || cream1 == 'Y')) || ((uCream == 'n' || uCream == 'N') && (cream1 == 'n' || cream1 == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n",   ((uStrenght == 'l' || uStrenght == 'L') && (type2 == 'l' || type2 == 'L')) || ((uStrenght == 'm' || uStrenght == 'M') && (type2 == 'm' || type2 == 'M')) || 
                                                                 ((uStrenght == 'r' || uStrenght == 'R') && (type2 == 'r' || type2 == 'R')), uServings >= 5 && uServings < 10,
                                                                 ((uCream == 'y' || uCream == 'Y') && (cream2 == 'y' || cream2 == 'Y')) || ((uCream == 'n' || uCream == 'N') && (cream2 == 'n' || cream2 == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((uStrenght == 'l' || uStrenght == 'L') && (type3 == 'l' || type3 == 'L')) || ((uStrenght == 'm' || uStrenght == 'M') && (type3 == 'm' || type3 == 'M')) || 
                                                                 ((uStrenght == 'r' || uStrenght == 'R') && (type3 == 'r' || type3 == 'R')), uServings >= 10, 
                                                                 ((uCream == 'y' || uCream == 'Y') && (cream3 == 'y' || cream3 == 'Y')) || ((uCream == 'n' || uCream == 'N') && (cream3 == 'n' || cream3 == 'N')));

    printf("Hope you found a product that suits your likes!\n");

    return 0;
}
