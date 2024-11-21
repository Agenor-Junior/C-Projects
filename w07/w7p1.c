/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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
#include "header.h"

int main(void)
{
    int maxMove, i,j, minMove = 3;
    struct PlayerInfo player1;
    struct  GameInfo  game1;

    //============================================================================START HERE
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    //------------------------------------------------------------------PLAYER CONFIGURATION
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player1.namePlayer);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player1.nLives);

        if (player1.nLives < LIVES_MIN || player1.nLives >LIVES_MAX)
        {
            printf("     Must be between %d and %d!\n", LIVES_MIN, LIVES_MAX);
        }

    } while (player1.nLives < LIVES_MIN || player1.nLives > LIVES_MAX);

    printf("Player configuration set-up is complete\n\n");

    //--------------------------------------------------------------------GAME CONFIGURATION
    printf("GAME Configuration\n");
    printf("------------------\n");

    //-------------------------------------------------------------------------- PATH LENGHT
    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", 
                                       DIVISOR, LENGTH_MIN, LENGTH_MAX);
        scanf("%d", &game1.pathLenght);

        if (game1.pathLenght % DIVISOR != 0 || 
           (game1.pathLenght < LENGTH_MIN || game1.pathLenght > LENGTH_MAX))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", 
                                         DIVISOR, LENGTH_MIN, LENGTH_MAX);
        }

    } while (game1.pathLenght % DIVISOR != 0 || 
            (game1.pathLenght < LENGTH_MIN || game1.pathLenght > LENGTH_MAX));

    //-----------------------------------------------------------------------NUMBER OF MOVES
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game1.moves);
        maxMove = game1.pathLenght * 3 / 4;

        if (game1.moves < minMove || game1.moves > maxMove)
        {
            printf("    Value must be between %d and %d\n", minMove, maxMove);
        }

    } while (game1.moves < minMove || game1.moves > maxMove);

    //------------------------------------------------------------------------BOMB PLACEMENT
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", DIVISOR);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game1.pathLenght);

    for (i = 1; i <= game1.pathLenght; i += DIVISOR)
    {
        printf("   Positions [%2d-%2d]: ", i, i + (DIVISOR - 1));

        for (j = 1; j <= DIVISOR; j++)
        {
            scanf("%d", &game1.setBomb[i + j - 1]);
        }
    }

    printf("BOMB placement set\n\n");

    //--------------------------------------------------------------------TREASURE PLACEMENT
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", DIVISOR);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game1.pathLenght);

    for (i = 1; i <= game1.pathLenght; i += DIVISOR)
    {
        printf("   Positions [%2d-%2d]: ", i, i + (DIVISOR - 1));

        for (j = 1; j <= DIVISOR; j++)
        {
            scanf("%d", &game1.setTreas[i + j - 1]);
        }
    }

    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");

    //-------------------------------------------------------DISPLAY CONFIGURATIONS SETTINGS
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    //------------------------------------------------------------------------DISPLAY PLAYER
    printf("Player:\n");
    printf("   Symbol     : %c\n", player1.namePlayer);
    printf("   Lives      : %d\n", player1.nLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    player1.treasures = 0;
    for (i = 1; i <= game1.pathLenght; i++)
    {
        player1.positHist[i] = '-';
    }

    //--------------------------------------------------------------------------DISPLAY GAME
    printf("\nGame:\n");
    printf("   Path Length: %d\n", game1.pathLenght);
    printf("   Bombs      : ");

    for (i = 1; i <= game1.pathLenght; i++)
    {
        printf("%d", game1.setBomb[i]);
    }

    printf("\n   Treasure   : ");

    for (i = 1; i <= game1.pathLenght; i++)
    {
        printf("%d", game1.setTreas[i]);
    }

    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}
