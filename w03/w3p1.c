/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Agenor Dionizio da SIlva Junior
Student ID#: 138121223
Email      : adionizio-da-silva-j@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    const double testValue = 330.99;
    double average;

    //---------------------------------------------------------------------PRODUCT 1 VARIABLES
    const int    product1 = 111;
    const double price1 = 111.49;
    const char   tax1 = 'Y';

    //---------------------------------------------------------------------PRODUCT 2 VARIABLES
    const int    product2 = 222;
    const double price2 = 222.99;
    const char   tax2 = 'N';

    //---------------------------------------------------------------------PRODUCT 3 VARIABLES
    const int    product3 = 111;
    const double price3 = 334.49;
    const char   tax3 = 'N';

    //==============================================================================START HERE

    //------------------------------------------------------------------------- #1 INFORMATION
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", product1);
    printf("  Taxed: %c\n", tax1);
    printf("  Price: $%.4f\n\n", price1);

    printf("Product-2 (ID:%d)\n", product2);
    printf("  Taxed: %c\n", tax2);
    printf("  Price: $%.4f\n\n", price2);

    printf("Product-3 (ID:%d)\n", product3);
    printf("  Taxed: %c\n", tax3);
    printf("  Price: $%.4f\n\n", price3);

   average = (price1 + price2 + price3) / 3;
    printf("The average of all prices is: $%.4f\n\n", average);

    //------------------------------------------------------------------------------- #2 ABOUT
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    //----------------------------------------------------------------------- #3 DATA ANALYSIS
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", (tax1 == 'Y'));

    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n",
        (tax2 == 'N' && tax3 == 'N'));

    printf("3. Is product 3 less than testValue ($%.2f)? -> %d\n\n",
        testValue, (price3 < testValue));

    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n",
        (price3 > (price1 + price2)));

    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n\n",
        (price1 >= (price3 - price2)), (price3 - price2));

    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n",
        (price2 >= average));

    printf("7. Based on product ID, product 1 is unique -> %d\n\n",
        !(product1 == product2 || product1 == product3));

    printf("8. Based on product ID, product 2 is unique -> %d\n\n",
        !(product2 == product1 || product2 == product3));

    printf("9. Based on product ID, product 3 is unique -> %d\n",
        !(product3 == product1 || product3 == product2));

    return 0;
}
