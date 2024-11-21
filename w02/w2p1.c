/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    int shirtS, shirtM, shirtL, cent, quantity, subtotalCents,taxesCents, totalCents;
    double shirtSprice, shirtMprice, shirtLprice, subtotal, taxes, total;

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
    scanf("%d", &quantity);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n",quantity);    

    subtotalCents = (int)((shirtSprice * quantity) * 100 + 0.5);
    subtotal = (double) subtotalCents / 100;
    printf("Sub-total: $%8.4lf\n", subtotal);
    taxesCents = (int)((subtotal * TAX) * 100 + 0.5);
    taxes = (double)taxesCents / 100;
    printf("Taxes    : $%8.4lf\n", taxes);
    totalCents = (int)((subtotal + taxes) * 100 + 0.5);
    total = (double)totalCents / 100;    
    printf("Total    : $%8.4lf\n", total);

    return 0;
}
