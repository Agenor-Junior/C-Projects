/*Workshop - #4 (P1)
Full Name : Agenor Dionizio da Silva Junior
Student ID# : 138121223
Email : adionizio - da - silva - j@myseneca.ca
Section : NRB
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.*/
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    //-------------------------------------------------------------------------------VARIABLES
    char typeLoop;
    int nunInteract, i;

    //==============================================================================START HERE
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do
    {
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &typeLoop, &nunInteract);

        if (typeLoop != 'D' && typeLoop != 'W' && typeLoop != 'F' && typeLoop != 'Q')
        {
            printf("ERROR: Invalid entered value(s)!");
        }

        else
        {

    //-------------------------------------------------------------------------- LOOP DO WHILE
            if (typeLoop == 'D')
            {
                if (nunInteract > 2 && nunInteract < 21)
                {
                    printf("DO-WHILE: ");
                    do
                    {
                        nunInteract--; printf("%c", typeLoop);

                    } while (nunInteract > 0);
                }

                else
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                }
            }

    //----------------------------------------------------------------------------- LOOP WHILE
            else if (typeLoop == 'W')
            {
                if (nunInteract > 2 && nunInteract < 21)
                {
                    printf("WHILE   : ");
                    while (nunInteract > 0)
                    {
                        printf("%c", typeLoop); nunInteract--;
                    }
                }
                else
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                }
            }

    //------------------------------------------------------------------------------- LOOP FOR
            else if (typeLoop == 'F')
            {
                if (nunInteract > 2 && nunInteract < 21)
                {
                    printf("FOR     : ");
                    for (i = 0; i < nunInteract; i++)
                    {
                        printf("%c", typeLoop);
                    }
                }
                else 
                { 
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!"); 
                }
            }

    //----------------------------------------------------------------------------- ERROR QUIT
            else
            {
                if (nunInteract != 0)
                {
                    printf("ERROR: To quit, the number of iterations should be 0!");
                }
            }
        }
        printf("\n");

    } while (!(typeLoop == 'Q' && nunInteract == 0));

    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}
