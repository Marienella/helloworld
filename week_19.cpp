#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
	char userName[50];
	char firstName[50];
	char lastName[50];
	char displayName[50];
	char jobTitle[50];
	char dep[50];
	int officeNumber;
	char officePhone[20];
	char mobileNumber[20];
	char fax[50];
	char address[50];
	char city[50];
	char state[10];
	char zipPostCode[20];
	char country[20];
} contact;

contact *contacts[50];

int numContacts = 0;

int readFile(char *fileName);
void printContact(contact *aContact);
void initialiseResults();

int main()
{
	char fileName[] = "F:\\contacts.txt";
	int i = 0;

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}


	while (contacts[i] != NULL)
	{
		printContact(contacts[i]);
		i++;
	}


	return 0;

}

int readFile(char *fileName)
{
	//put code here
	char line[300];

	int i = 0;

	char *token;
	char delim[] = ",";

	FILE *fptr = fopen(fileName, "r");

	fgets(line, 300, fptr);

	while (!feof(fptr))
	{
		fgets(line, 300, fptr);
		contacts[numContacts] = (contact*)malloc(sizeof(contact));

		token = strtok(line, delim);
		strcpy(contacts[numContacts]->userName, token);


		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->firstName, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->lastName, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->displayName, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->jobTitle, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->dep, token);

		token = strtok(NULL, delim);
		contacts[numContacts]->officeNumber = atoi(token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->officePhone, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->mobileNumber, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->fax, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->address, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->city, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->state, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->zipPostCode, token);

		token = strtok(NULL, delim);
		strcpy(contacts[numContacts]->country, token);


		numContacts++;

	}

	fclose(fptr);
	return 1;
}

void printContact(contact *aContact)
{
	printf("UserName: %s\nFirstName: %s\nLastName: %s\nDisplayName: %s\nJobTitle: %s\nDepartment: %s\nOficeNumber: %d\nOfficePhone: %s\nMobileNumber: %s\nFax: %s\nAddress: %s\nCity: %s\nState: %s\nZip/Postcode: %s\nCountry: %s\n\n", aContact->userName, aContact->firstName, aContact->lastName, aContact->displayName, aContact->jobTitle, aContact->dep, aContact->officeNumber, aContact->officePhone, aContact->mobileNumber, aContact->fax, aContact->address, aContact->city, aContact->state, aContact->zipPostCode, aContact->country);
}

void initialiseResults()
{
	int i = 0;
	while (i < 100)
	{
		*(contacts + i) = NULL;
		i++;
	}
}
