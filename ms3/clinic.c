/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :Agenor Dionizio da Silva Junior
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
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
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
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

    do {
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
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, found = 1;
    if (fmt == FMT_TABLE) 
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            found = 0;
        }
    }

    if (found) 
    {
        printf("*** No records found ***\n");
    }
    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int flag = 1;
    int select;
    while (flag == 1)
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

        if (select == 1)
        {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }

        else if (select == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }

        else if (select == 0)
        {
            printf("\n");
            flag = 0;
        }
    }
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int newPatient = 0, Index = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            newPatient++;
        }

        else
        {
            if (Index == 0)
            {
                Index = i;
            }
        }
    }

    if (newPatient < max)
    {
        patient[Index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[Index]);
        printf("*** New patient record added ***\n\n");
    }

    else
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int i;
    int patientNumber;

    printf("Enter the patient number: ");
    patientNumber = inputInt();
    printf("\n");
    i = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (i == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }

    else
    {
        menuPatientEdit(&patient[i]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int i, patientNumber;
    // char remove;
    printf("Enter the patient number: ");
    patientNumber = inputInt();
    printf("\n");
    i = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (i == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }

    else
    {
        displayPatientData(&patient[i], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): "); 

        if (inputCharOption("yn") == 'n')
        {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }

        else if (inputCharOption("yn") == 'y')
        {
            patient[i].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:

void viewAllAppointments(struct ClinicData* dataAppoint)
{
    int i, j;

    displayScheduleTableHeader(&dataAppoint->appointments->date, ALL_APPOINTMENTS);

    for (i = 0; i < dataAppoint->maxAppointments; i++)
    {
        for (j = 0; j < dataAppoint->maxPatient; j++)
        {
            if (dataAppoint->appointments[i].patientID && dataAppoint->patients[j].patientNumber)
            {
                if (dataAppoint->appointments[i].patientID == dataAppoint->patients[j].patientNumber)
                {
                    displayScheduleData(&dataAppoint->patients[j], &dataAppoint->appointments[i], 1);
                }
            }
        }
    }

    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* dataSchedule)
{
    struct Date schedule;
    int i, j;

    DateToInput(&schedule);    
    printf("\n");

    displayScheduleTableHeader(&schedule, SCHEDULE_APPOINTMENT);
        
    for (i = 0; i < dataSchedule->maxAppointments; i++)
    {
        for (j = 0; j < dataSchedule->maxPatient; j++)
        {
            if (dataSchedule->appointments[i].patientID && dataSchedule->patients[j].patientNumber)
            {
                if (dataSchedule->appointments[i].patientID == dataSchedule->patients[j].patientNumber)
                {
                    if (dataSchedule->appointments[i].date.year == schedule.year && dataSchedule->appointments[i].date.month == schedule.month && dataSchedule->appointments[i].date.day == schedule.day)
                    {
                        displayScheduleData(&dataSchedule->patients[j], &dataSchedule->appointments[i], 0);
                    }
                }
            }
        }
    }

    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoint, int maxAppointments, struct Patient* patient, int maxP)
{
    int i;
    int tmpPatientnum;
    int slotChecking;
    struct Date addingDate;
    struct Time addingTime;
    int freeSlot = 0;
    int a = 0;

    for (i = 0; i < maxAppointments; i++)
    {
        if (appoint[i].patientID < 1)            
        {
            freeSlot++;
            a = i;
        }
        if (freeSlot == 1)
        {
            i = maxAppointments;
        }
    }

    if (freeSlot == 0)        
    {
        puts("ERROR: Patient listing is FULL!\n");
    }

    else
    {
        printf("Patient Number: ");
        tmpPatientnum = inputIntPositive();

        do
        {
            slotChecking = 0;
            DateToInput(&addingDate);
            appointedTime(&addingTime);

            for (i = 0; i < maxAppointments; i++)               
            {
                if ((appoint[i].date.year == addingDate.year) && (appoint[i].date.month == addingDate.month) && (appoint[i].date.day == addingDate.day)
                    && (appoint[i].time.hour == addingTime.hour) && (appoint[i].time.min == addingTime.min))
                {
                    slotChecking++;
                }
            }

            if (slotChecking != 0)
            {
                puts("\nERROR: Appointment timeslot is not available!\n");
            }

            else
            {
                appoint[a].date.year = addingDate.year;
                appoint[a].date.month = addingDate.month;
                appoint[a].date.day = addingDate.day;
                appoint[a].time.hour = addingTime.hour;
                appoint[a].time.min = addingTime.min;
                appoint[a].patientID = tmpPatientnum;
            }

        } while (slotChecking != 0);

        puts("\n*** Appointment scheduled! ***\n");
    }
    SortingAppointments(appoint, maxAppointments);
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appoint, int maxAppointments, struct Patient* patient, int maxP)
{
    int i = 0;
    int patientRecord;
    int patientNum;
    int check = 0;
    char yesORno;
    struct Date appointDate;

    printf("Patient Number: ");
    patientNum = inputIntPositive();
    patientRecord = findPatientIndexByPatientNum(patientNum, patient, maxP);

    if (patientRecord == -1)
    {
        puts("ERROR: Patient record not found!\n");
    }

    else
    {
        DateToInput(&appointDate);
        printf("\nName  : %s\n", patient[patientRecord].name);
        printf("Number: %05d\n", patient[patientRecord].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[patientRecord].phone.number);
        printf(" (%s)\n", patient[patientRecord].phone.description);
        printf("Are you sure you want to remove this appointment (y,n): ");
        scanf(" %c", &yesORno);

        if (yesORno == 'y')
        {
            while (check == 0 && i < maxAppointments)
            {
                if ((appoint[i].patientID == patientNum) && (appoint[i].date.day == appointDate.day) &&
                    (appoint[i].date.month == appointDate.month) && (appoint[i].date.year == appointDate.year))                    
                {
                    check = 1;                    
                    appoint[i].patientID = 0;                    
                }
                i++;
            }
            puts("\nAppointment record has been removed!\n");
            clearInputBuffer();
        }
        else
        {
            puts("Cancelled\n");
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNum, indexPatient;
    printf("\n");
    printf("Search by patient number: ");
    patientNum = inputInt(); 
    indexPatient = findPatientIndexByPatientNum(patientNum, patient, max); 

    if (indexPatient == -1)       
    {
        printf("\n");
        printf("*** No records found ***\n");
        printf("\n");
    }

    else
    {
        printf("\n");
        displayPatientData(&patient[indexPatient], FMT_FORM);
        printf("\n");
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patientSearch[], int max)
{
    char phoneNum[PHONE_LEN + 1];
    int i, found;
    int j = 0;

    printf("\n");
    printf("Search by phone number: ");
    inputCString(phoneNum, 10, 10);
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        found = strcmp(phoneNum, patientSearch[i].phone.number);
        if (found == 0)
        {
            displayPatientData(&patientSearch[i], FMT_TABLE);
            j++; 
        }
    }

    if (j == 0)
    {
        printf("\n*** No records found ***\n");
    }

    printf("\n");
    clearInputBuffer();
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, nextPatientNum;
    int largest = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > largest)
        {
            largest = patient[i].patientNumber;
        }
    }

    nextPatientNum = largest + 1;
    return nextPatientNum;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {

        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }

    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &selection);

    switch (selection)
    {
        case 1:
            strcpy(phone->description, "CELL");
            printf("\n");
            printf("Contact: %s\n", phone->description);
            printf("Number : ");
            inputCString(phone->number, 10, 10);
            clearInputBuffer();
            printf("\n");
            break;
        case 2:
            strcpy(phone->description, "HOME");
            printf("\n");
            printf("Contact: %s\n", phone->description);
            printf("Number : ");
            inputCString(phone->number, 10, 10);
            clearInputBuffer();
            printf("\n");
            break;
        case 3:
            strcpy(phone->description, "WORK");
            printf("\n");
            printf("Contact: %s\n", phone->description);
            printf("Number : ");
            inputCString(phone->number, 10, 10);
            clearInputBuffer();
            printf("\n");
            break;
        case 4:
            strcpy(phone->description, "TBD");
            strcpy(phone->number, "");
            clearInputBuffer();
            printf("\n");
            break;
        default:
            printf("\n");
    }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;
    FILE* fp = NULL;
    fp = fopen(datafile, "r");   

    if (fp != NULL)
    {
        while (i < max && fscanf(fp, " %d|%15[^|]|%4[^|]|%10[^\n]\n",
            &patients[i].patientNumber, patients[i].name, patients[i].phone.description, 
            patients[i].phone.number) != EOF)
        {
            i++; 
        }

        fclose(fp);
    }

    else
    {
        printf("Failed to open file\n");
    }

    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i = 0;
    FILE* fp = NULL;

    fp = fopen(datafile, "r"); 

    if (fp != NULL)
    {
        while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientID, &appoints[i].date.year, &appoints[i].date.month,
            &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF)
        {
            i++;
        }
        fclose(fp);
    }

    else
    {
        printf("Failed to open file\n");
    }

    SortingAppointments(appoints, max);
    return i;    
}

//////////////////////////////////////
// MY FUNCTIONS
//////////////////////////////////////

void DateToInput(struct Date* inputedDate)
{
    int dayRange = 0;

    printf("Year        : ");
    inputedDate->year = inputIntPositive();

    printf("Month (1-12): ");
    inputedDate->month = inputIntRange(1, 12);

    if (inputedDate->month == 2 && inputedDate->year % 4 == 0)        
    {
        dayRange = 29;
        printf("Day (1-%d)  : ", dayRange);
    }

    else if (inputedDate->month == 4 || inputedDate->month == 9 || inputedDate->month == 11)      
    {
        dayRange = 30;
        printf("Day (1-%d)  : ", dayRange);
    }
    else if (inputedDate->month == 2)        
    {
        dayRange = 28;
        printf("Day (1-%d)  : ", dayRange);
    }

    else
    {
        dayRange = 31;
        printf("Day (1-%d)  : ", dayRange);
    }
    inputedDate->day = inputIntRange(1, dayRange);
}

void appointedTime(struct Time* appointment)
{
    int flag = 0;

    do
    {
        flag = 0;
        printf("Hour (0-23)  : ");
        appointment->hour = inputIntRange(0, 23);
        printf("Minute (0-59): ");
        appointment->min = inputIntRange(0, 59);

        if (appointment->hour == HOUR_CLOSE)
        {
            if (appointment->min == 0)
            {
                flag++;
            }
        }
        if (appointment->hour >= HOUR_OPEN && appointment->hour <= HOUR_CLOSE - 1)
        {

            if (appointment->min % MINUTE_INTERVAL == 0)
            {
                flag++;
            }
        }

        if (flag == 0)
        {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", HOUR_OPEN, HOUR_CLOSE, MINUTE_INTERVAL);
        }
    } while (flag == 0);
}

void SortingAppointments(struct Appointment appointment[], int max)
{
    int i = 0, j = 0, swaping;
    struct Appointment appointTemp = { 0 };

    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max; j++)
        {
            swaping = 0;

            if (appointment[i].date.year < appointment[j].date.year)                
            {
                swaping = 1;
            }

            if (appointment[i].date.year == appointment[j].date.year && appointment[i].date.month < appointment[j].date.month)                
            {
                swaping = 1;
            }

            if (appointment[i].date.year == appointment[j].date.year && appointment[i].date.month == appointment[j].date.month
                && appointment[i].date.day < appointment[j].date.day)                
            {
                swaping = 1;
            }

            if (appointment[i].date.year == appointment[j].date.year && appointment[i].date.month == appointment[j].date.month
                && appointment[i].date.day == appointment[j].date.day && appointment[i].time.hour < appointment[j].time.hour)                
            {
                swaping = 1;
            }

            if (appointment[i].date.year == appointment[j].date.year && appointment[i].date.month == appointment[j].date.month
                && appointment[i].date.day == appointment[j].date.day && appointment[i].time.hour == appointment[j].time.hour
                && appointment[i].time.min < appointment[j].time.min)               
            {
                swaping = 1;
            }

            if (swaping) 
            {
                appointTemp = appointment[i];
                appointment[i] = appointment[j];
                appointment[j] = appointTemp;
            }
        }
    }
}