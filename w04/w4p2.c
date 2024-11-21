/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Agenor Dionizio da SIlva Junior
Student ID#:138121223
Email      : adionizio-da-silva-j
Section    :NRB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int otherShop;

    //-------------------------------------------------------APPLES VARIABLES
    int appleNum, applePick = 0;

    //------------------------------------------------------ORANGES VARIABLES
    int orangeNum, orangePick = 0;

    //--------------------------------------------------------PEARS VARIABLES
    int pearNum, pearPick = 0;
    
    //-----------------------------------------------------CABBAGES VARIABLES
    int cabbageNum, cabbagePick = 0;

    //------------------------------------------------------TOMATOS VARIABLES
    int tomatoNum, tomatoPick = 0;    

    do 
    {

    //=============================================================START HERE
        printf("Grocery Shopping\n");
        printf("================\n");

        do 
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &appleNum);

            if (appleNum < 0)
            { 
                printf("ERROR: Value must be 0 or more.\n");
            }

            else
            { 
                printf("\n"); 
            }

        } while (appleNum < 0);

        do 
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &orangeNum);

            if (orangeNum < 0)
            { 
                printf("ERROR: Value must be 0 or more.\n");
            }

            else 
            { 
                printf("\n");
            }

        } while (orangeNum < 0);

        do 
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pearNum);

            if (pearNum < 0) 
            { 
                printf("ERROR: Value must be 0 or more.\n");
            }

            else 
            { 
                printf("\n"); 
            }

        } while (pearNum < 0);

        do 
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoNum);

            if (tomatoNum < 0) 
            { 
                printf("ERROR: Value must be 0 or more.\n");
            }

            else 
            { 
                printf("\n");
            }

        } while (tomatoNum < 0);

        do 
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbageNum);

            if (cabbageNum < 0) 
            { 
                printf("ERROR: Value must be 0 or more.\n"); 
            }

            else 
            { 
                printf("\n");
            }

        } while (cabbageNum < 0);

        //------------------------------------------------PICKING UP PRODUCTS

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");             

        while (appleNum != 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &applePick);

            if (applePick < 1) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (applePick > appleNum)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", appleNum);
            }

            else
            {
                if (applePick == appleNum) 
                {
                    printf("Great, that's the apples done!\n\n");
                    appleNum = 0;
                }

                else 
                {
                    printf("Looks like we still need some APPLES...\n");
                    appleNum = appleNum - applePick;
                }

            }

        }

        while (orangeNum != 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangePick);

            if (orangePick < 1) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (orangePick > orangeNum)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", orangeNum);
            }

            else 
            {
                if (orangePick == orangeNum) 
                {
                    printf("Great, that's the oranges done!\n\n");
                    orangeNum = 0;
                }

                else {
                    printf("Looks like we still need some ORANGES...\n");
                    orangeNum = orangeNum - orangePick;
                }

            }

        }

        while (pearNum != 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pearPick);

            if (pearPick < 1) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (pearPick > pearNum)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pearNum);
            }

            else
            {
                if (pearPick == pearNum) 
                {
                    printf("Great, that's the pears done!\n\n");
                    pearNum = 0;
                }

                else 
                {
                    printf("Looks like we still need some PEARS...\n");
                    pearNum = pearNum - pearPick;
                }

            }

        }

        while (tomatoNum != 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoPick);

            if (tomatoPick < 1) 
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (tomatoPick > tomatoNum)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoNum);
            }

            else 
            {
                if (tomatoPick == tomatoNum) 
                {
                    printf("Great, that's the tomatoes done!\n\n");
                    tomatoNum = 0;
                }

                else 
                {
                    printf("Looks like we still need some TOMATOES...\n");
                    tomatoNum = tomatoNum - tomatoPick;
                }

            }

        }

        while (cabbageNum != 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &cabbagePick);

            if (cabbagePick < 1)
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if (cabbagePick > cabbageNum)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbageNum);
            }

            else 
            {
                if (cabbagePick == cabbageNum) 
                {
                    printf("Great, that's the cabbages done!\n\n");
                    cabbageNum = 0;
                }

                else 
                {
                    printf("Looks like we still need some CABBAGES...\n");
                    cabbageNum = cabbageNum - cabbagePick;
                }

            }

        }

        printf("All the items are picked!\n");
        printf("\nDo another shopping? (0=NO): ");
        scanf("%d", &otherShop);
        printf("\n");

    } while (otherShop > 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
