/*1. Napisati program koji prvo pro?ita koliko redaka ima datoteka, tj.koliko ima studenata
zapisanih u datoteci.Nakon toga potrebno je dinami?ki alocirati prostor za niz struktura
studenata(ime, prezime, bodovi) i u?itati iz datoteke sve zapise.Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova / max_br_bodova * 100*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define MAXNOPOINTS 80



typedef struct {
	char name[MAX];
	char surname[MAX];
	int points;
} student;


int readNoRows();

int readStudentsFromFile(student* base);

int printStudentsFromFile(student* base, int brred);


int main() {
	int noRows;
	student* base;


	noRows = readNoRows();

	base = malloc(sizeof(student) * noRows);

	readStudentsFromFile(base);

	printStudentsFromFile(base, noRows);


	return 0;
}

int readNoRows() {
	int counter = 0;
	FILE* studentsFile = NULL;
	char buffer[MAX] = { 0 };

	studentsFile = fopen("students.txt", "r");

	if (!studentsFile) {
		printf("File not opened");
		return -1;
	}


	while (!feof(studentsFile)) {
		fgets(buffer, MAX, studentsFile);
		counter++;
	}


	fclose(studentsFile);

	return counter;
};

int readStudentsFromFile(student* base) {
	FILE* studentsFile = NULL;
	int i = 0;

	studentsFile = fopen("students.txt", "r");

	while (!feof(studentsFile)) {
		fscanf(studentsFile, "%s %s %d", base[i].name, base[i].surname, &base[i].points);
		i++;
	}

	fclose(studentsFile);

	return 0;
}

int printStudentsFromFile(student* base, int noRows) {
	double relPoints = 0.0;
	int i = 0;

	for (i = 0; i < noRows; i++) {
		relPoints = ((double)base[i].points / MAXNOPOINTS) * 100;

		printf("\n Ucenik %s %s je imao/la apsolutan broj bodova od %d i relativan od %lf\n", base[i].name, base[i].surname, base[i].points, relPoints);
	}

	return 0;
}
