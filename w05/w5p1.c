/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Agenor Dionizio da Silva Junior
Student ID#: 138121223
Email      :adionizio-da-silva-j@myseneca.ca
Section    :NRB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    //----------------------------------------------------------- VARIABLES
    const int JAN = 1, DEC = 12;
    int setYear, setMonth, initialDay = 1;

    //========================================================== START HERE
    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &setYear, &setMonth);

        if (!(MIN_YEAR <= setYear && setYear <= MAX_YEAR) && (JAN <= setMonth && setMonth <= DEC))
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        else if ((MIN_YEAR <= setYear && setYear <= MAX_YEAR) && !(JAN <= setMonth && setMonth <= DEC))
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }

        else if (!(MIN_YEAR <= setYear && setYear <= MAX_YEAR) && !(JAN <= setMonth && setMonth <= DEC))
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }

        else
        {
            printf("\n*** Log date set! ***\n\n");
            printf("Log starting date: ");

            switch (setMonth)
            {
            case  1: printf("%d-JAN-%02d\n", setYear, initialDay); break;
            case  2: printf("%d-FEB-%02d\n", setYear, initialDay); break;
            case  3: printf("%d-MAR-%02d\n", setYear, initialDay); break;
            case  4: printf("%d-APR-%02d\n", setYear, initialDay); break;
            case  5: printf("%d-MAY-%02d\n", setYear, initialDay); break;
            case  6: printf("%d-JUN-%02d\n", setYear, initialDay); break;
            case  7: printf("%d-JUL-%02d\n", setYear, initialDay); break;
            case  8: printf("%d-AUG-%02d\n", setYear, initialDay); break;
            case  9: printf("%d-SEP-%02d\n", setYear, initialDay); break;
            case 10: printf("%d-OCT-%02d\n", setYear, initialDay); break;
            case 11: printf("%d-NOV-%02d\n", setYear, initialDay); break;
            case 12: printf("%d-DEC-%02d\n", setYear, initialDay); break;
            default: printf("error data"); break;
            }

        }

    } while (!(MIN_YEAR <= setYear && setYear <= MAX_YEAR) || !(JAN <= setMonth && setMonth <= DEC));

    return 0;
}
