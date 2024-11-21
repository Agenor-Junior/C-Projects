/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Agenor Dionizio da Silva Junior
Student ID#: 1381121223
Email      : adionizio-da-silva-j@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do 
    {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
            case 0:
                printf("Are you sure you want to exit? (y|n): ");
                selection = !(inputCharOption("yn") == 'y');
                putchar('\n');

                if (!selection)
                {
                    printf("Exiting system... Goodbye.\n\n");
                }
                break;

            case 1:
                menuPatient(data->patients, data->maxPatient);
                break;

            case 2:
                printf("<<< Feature not yet available >>>\n\n");
                break;
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do 
    {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");

        selection = inputIntRange(0, 5);
        putchar('\n');

        switch (selection)
        {
            case 1:
                displayAllPatients(patient, max, FMT_TABLE);
                suspend();
                break;

            case 2:
                searchPatientData(patient, max);
                break;

            case 3:
                addPatient(patient, max);
                suspend();
                break;

            case 4:
                editPatient(patient, max);
                break;

            case 5:
                removePatient(patient, max);
                suspend();
                break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do 
    {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);

        if (selection == 1)
        {
            printf("\nName  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }

        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("\nPatient record updated!\n\n");
        }

    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------
// 
//=============================================================================
// 
// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, match = 0;
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            match++;
        }
    }

    if (match == 0)
    {
        printf("*** No records found ***");
    }
    printf("\n");
}

//=============================================================================
// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int select;
    do
    {
        do
        {
            printf("Search Options\n");
            printf("==========================\n");
            printf("1) By patient number\n");
            printf("2) By phone number\n");
            printf("..........................\n");
            printf("0) Previous menu\n");
            printf("..........................\n");
            printf("Selection: ");
            scanf("%d", &select);
            clearInputBuffer();

            if (select > 2 || select < 0) { printf("\n"); }

        } while (select > 2 || select < 0);

        switch (select)
        {
            case 0: printf("\n");
                break;

            case 1: searchPatientByPatientNumber(patient, max);
                break;

            case 2: searchPatientByPhoneNumber(patient, max);
                break;
        }

    } while (select != 0);
}

//============================================================================
// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i, nextId, newPosition = -1;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            newPosition = i;
            break;
        }
    }

    if (newPosition == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }

    else
    {
        nextId = nextPatientNumber(patient, max);
        patient[newPosition].patientNumber = nextId;
        inputPatient(&patient[newPosition]);
    }
}

//============================================================================
// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int checkID, foundedID = -1;

    printf("Enter the patient number: ");
    scanf("%d", &checkID);
    putchar('\n');

    foundedID = findPatientIndexByPatientNum(checkID, patient, max);

    if (foundedID == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
        suspend();
    }

    else
    {
        menuPatientEdit(&patient[foundedID]);
        putchar('\n');
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int checkID, foundedID = -1;
    char option;

    printf("Enter the patient number: ");
    scanf("%d", &checkID);
    clearInputBuffer();

    putchar('\n');
    foundedID = findPatientIndexByPatientNum(checkID, patient, max);

    if (foundedID == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }

    else
    {
        displayPatientData(&patient[foundedID], FMT_FORM);
        putchar('\n');

        printf("Are you sure you want to remove this patient record? (y/n): ");
        option = inputCharOption("yn");

        if (option == 'y')
        {
            patient[foundedID].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }

        else
        {
            printf("Operation aborted.\n\n");
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

//==============================================================================
// // Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber;
    printf("\nSearch by patient number: ");
    scanf("%d", &patientNumber);
    clearInputBuffer();
    int found = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (found == -1)
    {
        printf("\n*** No records found ***\n\n");
    }

    else
    {
        putchar('\n');
        displayPatientData(&patient[found], FMT_FORM);
        putchar('\n');
    }

    suspend();
}


//================================================================================
// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, phoneFound = 0;
    char telephone[10 + 1];
    printf("\nSearch by phone number: ");
    scanf("%10s", telephone);
    clearInputBuffer();
    putchar('\n');
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (strcmp(telephone, patient[i].phone.number) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            phoneFound++;
        }
    }

    if (phoneFound == 0)
    {
        putchar('\n');
        printf("*** No records found ***\n");
    }

    putchar('\n');
    suspend();
}

//================================================================================
// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, higherID = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > higherID)
        {
            higherID = patient[i].patientNumber;
        }
    }
    higherID++;
    return higherID;
}

//================================================================================
// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i, patientFound = -1;

    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            patientFound = i;
            break;
        }
    }

    return patientFound;
}

//================================================================================

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//================================================================================
// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    scanf("%[^\n]", patient->name);
    clearInputBuffer();
    inputPhoneData(&patient->phone);
    printf("\n");
    printf("*** New patient record added ***\n\n");
}


//================================================================================
// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone* phone)
{
    int select;
    printf("\nPhone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &select);
    clearInputBuffer();

    if (select == 4)
    {
        strcpy(phone->description, "TBD");
        phone->number[0] = 0;
    }

    else
    {
        switch (select)
        {
            case 1: strcpy(phone->description, "CELL");
                break;

            case 2: strcpy(phone->description, "HOME");
                break;

            case 3: strcpy(phone->description, "WORK");
                break;
        }

        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        scanf("%10s", phone->number);
        clearInputBuffer();
    }
}