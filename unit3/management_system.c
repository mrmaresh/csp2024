#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>  //system("clear");

typedef struct {
    string name;
    int age;
    string gender;
    string lastVisit;
} Patient;

void addPatient(Patient patients[], int numPatients);

int main(void){
    Patient patients[300];
    int numPatients = 0;
    int choice = 0;
    while (choice != 3){
        printf("\n---- Hospital Management System ----\n");
        printf("1. Add a new patient\n");
        printf("2. Search for a patient\n");
        printf("3. Exit\n");
        choice = get_int("Enter your choice: ");
        system("clear");
        if (choice == 1){
            addPatient(patients, numPatients);
            numPatients = numPatients + 1;
        }
        else if (choice == 2){
            searchPatient(patients, numPatients);
        }
        else if (choice == 3){
            printf("Exiting ... \n");
        }
        else{
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addPatient(Patient patients[], int numPatients){
    Patient newPatient;
    newPatient.name = get_string("Enter patient name: ");
    newPatient.age = get_int("Enter age: ");
    newPatient.gender = get_string("Enter gender: ");
    newPatient.lastVisit = get_string("Enter the last visit date (mm-dd-yyyy): ");
    patients[numPatients] = newPatient;
}


void searchPatient(Patients patients[], int numPatients){
    //Prompt for patient name
    //Search for patient name
    //If we find a match,
    //    print out patient info
    string name = get_string("Enter the patients name to search: ");
    for (int i = 0; i < numPatients; i = i + 1){
        if(strcmp(patient.name, name) == 0){
            //do something
        }
    }

}
