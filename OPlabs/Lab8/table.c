#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "table.h"

#define SURNAME_SIZE 14
#define NAME_SIZE 10

void PrintSpaces(FILE *f, int n)
{
	for(int i = 0; i < n; i++)
		fprintf(f, " ");
}

void PrintRow(FILE *f, const struct student *s, int n)
{
	fprintf(f, "| %02d ", n);
	fprintf(f, "| %s", s->surname);
	PrintSpaces(f, SURNAME_SIZE - strlen(s->surname) / 2 - 1);
	fprintf(f, "| %s", s->name);
	PrintSpaces(f, NAME_SIZE - strlen(s->name) / 2 - 1);
	fprintf(f, "| %s ", s->birthdate);
	fprintf(f, "| %02d ", s->ExamGrade.OP);
	fprintf(f, "|  %02d  ", s->ExamGrade.CDM);
	fprintf(f, "| %02d ", s->ExamGrade.Calculus);
	fprintf(f, "|  %02d  ", s->ExamGrade.LAAG);
	fprintf(f, "|  %02d  |", s->ExamGrade.History);
	fprintf(f, "\n");
}

void PrintTable(FILE *f, const struct student arr[], int size,
		int (*condition)(const struct student*, float), float n)
{
	fprintf(f, "---------------------------------------------"\
			   "-------------------------------\n");
	fprintf(f, "|    |              |          |    дата    |"\
			   " Список екзаменаційних оцінок |\n");
	fprintf(f, "| №  |   Прізвище   |   Ім'я   |            |"\
			   "------------------------------|\n");
	fprintf(f, "|    |              |          | народження |"\
			   " ОП | КДМ  | MA | ЛААГ | Іст. |\n");
	fprintf(f, "---------------------------------------------"\
			   "-------------------------------\n");
	for(int i = 0; i < size; i++)
		if (condition(&arr[i], n))
			PrintRow(f, &arr[i], i + 1);
	fprintf(f, "---------------------------------------------"\
			   "-------------------------------\n");
}

float AverageRating(const struct student arr[], int size)
{
	float avr = 0; 
	for(int i = 0; i < size; i++){
		float sum = 0;
		sum += arr[i].ExamGrade.OP;
		sum += arr[i].ExamGrade.CDM;
		sum += arr[i].ExamGrade.Calculus;
		sum += arr[i].ExamGrade.LAAG;
		sum += arr[i].ExamGrade.History;
		avr += sum / 5;
	}
	return avr / 27;
}

int isGreaterThanAverageRating(const struct student *s, float avr)
{
	float n = 0;
	n += s->ExamGrade.OP;
	n += s->ExamGrade.CDM;
	n += s->ExamGrade.Calculus;
	n += s->ExamGrade.LAAG;
	n += s->ExamGrade.History;
	n /= 5;

	//printf("%lf %lf\n", avr, n);
	if (n < avr)
		return 1;
	return 0;

}

int True(const struct student *s, float avr)
{
	return 1;
}


void ReadList(FILE *f, struct student arr[], int size)
{
	char str[200] = "";
	for(int i = 0; i < size; i++){
		fgets(str, 200, f);
		char *token = strtok(str, " \n");
		strcpy(arr[i].surname, token);
		token = strtok(NULL, " \n");
		strcpy(arr[i].name, token);
		token = strtok(NULL, " \n");
		strcpy(arr[i].birthdate, token);
		token = strtok(NULL, " \n");
		arr[i].ExamGrade.OP = atoi(token);
		token = strtok(NULL, " \n");
		arr[i].ExamGrade.CDM = atoi(token);
		token = strtok(NULL, " \n");
		arr[i].ExamGrade.Calculus = atoi(token);
		token = strtok(NULL, " \n");
		arr[i].ExamGrade.LAAG = atoi(token);
		token = strtok(NULL, " \n");
		arr[i].ExamGrade.History = atoi(token);
		token = strtok(NULL, " \n");
	}
}
