#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct
{
	char firstName[50];
	char lastName[50];
	long id;
	char english, french, maths, philosophy;
} result;

// array of pointers to 'result' structures - assuming that there is 100 or less records in the data file
result *results[100];

// number of records read from the file
int numResults = 0;

//function to read file in data structures
int readFile(char *fileName);

// set all the pointers in *results[] to NULL before reading in the file
void initialiseResults();

// function to print an individual member of the *results[] array
void printResult(result *aResult);

int main()
{
	char fileName[] = "C:\\results.txt";
	int i = 0;


	void initialiseResults();

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}
	puts("ID\t\tFirstName\tSurName\tEnglish\tMaths\tFrench\tPhilosophy\n");
	while (results[i] != NULL)
	{
		printResult(results[i]);
		i++;
	}

	return 0;
}

void printResult(result *aResult)
{
	printf("%5ld\t%15s\t%15s\t%5c\t%5c\t%5c\t%5c\n", aResult->id, aResult->firstName, aResult->lastName, aResult->english, aResult->maths, aResult->french, aResult->philosophy);
}

void initialiseResults()
{
	int i = 0;
	while (i < 100)
	{
		*(results + i) = NULL;
		i++;
	}
}

int readFile(char *fileName)
{
	char line[300];

	int i = 0;
	int s = 0;

	char *token;
	char delim[] = "\t";

	FILE *fptr = fopen(fileName, "r");

	fgets(line, 300, fptr);//skips headings

	while (!feof(fptr))
	{
		results[numResults] = (result*)malloc(sizeof(result));

		fscanf(fptr, "%d %s %s %c %c %c %c", &results[numResults]->id, results[numResults]->firstName, results[numResults]->lastName, &results[numResults]->english, &results[numResults]->maths, &results[numResults]->french, &results[numResults]->philosophy);

		numResults++;
		fgets(line, 300, fptr);//gets next line
	}

	fclose(fptr);
	return 1;
}