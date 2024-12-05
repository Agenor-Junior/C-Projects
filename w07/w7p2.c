/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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
#include "header2.h"

int main(void)
{
    int i, j, minMove = 3, maxMove, moveSelect = 0;

    struct PlayerInfo player1;
    struct   GameInfo   game1;

    //============================================================================ START HERE
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    //------------------------------------------------------------------ PLAYER CONFIGURATION
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

    //-------------------------------------------------------------------- GAME CONFIGURATION
    printf("GAME Configuration\n");
    printf("------------------\n");

    //--------------------------------------------------------------------------- PATH LENGHT
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

    //----------------------------------------------------------------------- NUMBER OF MOVES
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

    //------------------------------------------------------------------------ BOMB PLACEMENT
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

    //-------------------------------------------------------------------- TREASURE PLACEMENT
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

    //------------------------------------------------------- DISPLAY CONFIGURATIONS SETTINGS
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    //------------------------------------------------------------------------ DISPLAY PLAYER
    printf("Player:\n");
    printf("   Symbol     : %c\n", player1.namePlayer);
    printf("   Lives      : %d\n", player1.nLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    //--------------------------------------------------------------------------- SETTING MAP
    player1.treasures = 0;

    for (i = 1; i <= game1.pathLenght; i++)
    {
        player1.positHist[i] = '-';
    }

    for (i = 1; i <= game1.pathLenght; i++)
    {
        if (i % 10 == 0)
        {
            game1.tenMap[i] = (char)i / 10 + '0';
        }

        else
        {
            game1.tenMap[i] = '|';
        }
    }

    for (i = 1; i <= game1.pathLenght; i++)
    {
        if (i % 10 == 0)
        {
            game1.unitMap[i] = 0;
        }

        else
        {
            game1.unitMap[i] = i % 10;
        }
    }

    //-------------------------------------------------------------------------- DISPLAY GAME
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

    //******************************************************************************** PART 2
    
    do
    {
        //--------------------------------------------------------------------- DISPLAYNG MAP

        if (moveSelect != 0)
        {
            printf("  ");
            for (i = 1; i < moveSelect; i++)
            {
                printf(" ");
            }
            printf("V");
        }


        printf("\n  ");
        for (i = 1; i <= game1.pathLenght; i++)
        {
            printf("%c", player1.positHist[i]);

        }

        printf("\n  ");
        for (i = 1; i <= game1.pathLenght; i++)
        {
            printf("%c", game1.tenMap[i]);
        }

        printf("\n  ");
        for (i = 1; i <= game1.pathLenght; i++)
        {
            printf("%d", game1.unitMap[i]);
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %2d\n",
                           player1.nLives, player1.treasures, game1.moves);
        printf("+---------------------------------------------------+\n");


        //-------------------------------------------------------------- GETTING NEW MOVE 
        do
        {
            printf("Next Move [1-%d]: ", game1.pathLenght);
            scanf("%d", &moveSelect);

            if (moveSelect < 1 || moveSelect > game1.pathLenght)
            {
                printf("  Out of Range!!!\n");
            }

        } while (moveSelect < 1 || moveSelect > game1.pathLenght);

        
        
        //------------------------------------------------------- POSITION CHOOSED BEFORE
        if (player1.positHist[moveSelect] != '-')                                          
        {
            printf("\n===============> Dope! You've been here before!\n\n");
        }

        //------------------------------------------------------------- BOMB AND TREASURE
        else if (game1.setBomb[moveSelect] == 1 && game1.setTreas[moveSelect] == 1)              
        {
            printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            player1.positHist[moveSelect] = '&';
            game1.moves--;
            player1.nLives--;
            player1.treasures++;
        }

        //--------------------------------------------------------------------- ONLY BOMB
        else if (game1.setBomb[moveSelect] == 1 && game1.setTreas[moveSelect] == 0)                      
        {
            printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
            player1.positHist[moveSelect] = '!';
            game1.moves--;
            player1.nLives--;
        }

        //----------------------------------------------------------------- ONLY TREASURE
        else if (game1.setBomb[moveSelect] == 0 && game1.setTreas[moveSelect] == 1)                  
        {
            printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            player1.positHist[moveSelect] = '$';
            game1.moves--;
            player1.treasures++;
        }

        //----------------------------------------------------------------- NOTHING FOUND
        else
        {
            printf("\n===============> [.] ...Nothing found here... [.]\n\n");                       
            player1.positHist[moveSelect] = '.';
            game1.moves--;
        }

    } while (player1.nLives > 0);

    //---------------------------------------------- PRINTING MAP NO MORE LIVES REMAINING
    printf("No more LIVES remaining!\n\n");

    if (moveSelect != 0)
    {
        printf("  ");

        for (i = 1; i < moveSelect; i++)
        {
            printf(" ");
        }
        printf("V");
    }
    printf("\n  ");

    for (i = 1; i <= game1.pathLenght; i++)
    {
        printf("%c", player1.positHist[i]);
    }
    printf("\n  ");

    for (i = 1; i <= game1.pathLenght; i++)
    {
        printf("%c", game1.tenMap[i]);
    }
    printf("\n  ");

    for (i = 1; i <= game1.pathLenght; i++)
    {
        printf("%d", game1.unitMap[i]);
    }

    printf("\n");
    printf("+---------------------------------------------------+\n");
    printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %2d\n", 
                       player1.nLives, player1.treasures, game1.moves);
    printf("+---------------------------------------------------+\n");

    //----------------------------------------------------------------- MESSAGE GAME OVER
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\nYou should play again and try to beat your score!\n");

    return 0;
}
//end
