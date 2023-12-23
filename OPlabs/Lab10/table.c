#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "table.h"

enum{
	nSurnamenSize = 14,
	nNamenSize = 10,
};

//==============================================================================

void PrintSpaces(FILE *pFile, int n)
{
	for(int i = 0; i < n; i++)
		fprintf(pFile, " ");
}

//==============================================================================

void PrintRow(FILE *pFile, const struct SStudent *s, int n)
{
	fprintf(pFile, "| %02d ", n);
	fprintf(pFile, "| %s", s->szSurname);
	PrintSpaces(pFile, nSurnamenSize - strlen(s->szSurname) / 2);

	fprintf(pFile, "| %s", s->szName);
	PrintSpaces(pFile, nNamenSize - strlen(s->szName) / 2);

	fprintf(pFile, "| %02d.%02d.%04d ",	
		s->nBirthdate[0], s->nBirthdate[1], s->nBirthdate[2]);

	fprintf(pFile, "| %02d ", 	 s->nExamGrade[0]);
	fprintf(pFile, "|  %02d  ",  s->nExamGrade[1]);
	fprintf(pFile, "| %02d ", 	 s->nExamGrade[2]);
	fprintf(pFile, "|  %02d  ",  s->nExamGrade[3]);
	fprintf(pFile, "|  %02d  |", s->nExamGrade[4]);

	fprintf(pFile, "\n");
}

//==============================================================================

void PrintTable(FILE *pFile, const struct SStudent pArr[], int nSize,
		int (*condition)(const struct SStudent*, float), float n)
{
	//take n as a parameter for condition function
	fprintf(pFile, "---------------------------------------------"\
			   "-------------------------------\n");
	fprintf(pFile, "|    |              |          |    Дата    |"\
			   " Список екзаменаційних оцінок |\n");
	fprintf(pFile, "| №  |   Прізвище   |   Ім'я   |            |"\
			   "------------------------------|\n");
	fprintf(pFile, "|    |              |          | народження |"\
			   " ОП | КДМ  | MA | ЛААГ | Іст. |\n");
	fprintf(pFile, "---------------------------------------------"\
			   "-------------------------------\n");

	for(int i = 0; i < nSize; i++)
		if (condition(&pArr[i], n))
			PrintRow(pFile, &pArr[i], i + 1);

	fprintf(pFile, "---------------------------------------------"\
			   "-------------------------------\n");
}

//==============================================================================

float AverageRating(const struct SStudent pArr[], int nSize)
{
	float nAvr = 0; 
	for(int i = 0; i < nSize; i++){
		float nSum = 0;
		for(int j = 0; j < nExamGradesAmount; j++)
			nSum += pArr[i].nExamGrade[j];
		nAvr += nSum / nExamGradesAmount;
	}
	return nAvr / nSize;
}

//==============================================================================

int IsRatingGreaterThan(float nAvr, const struct SStudent *s)
{
	float nSum = 0;
	for(int i = 0; i < nExamGradesAmount; i++)
		nSum += s->nExamGrade[i];
	nSum /= nExamGradesAmount;

	if (nSum < nAvr)
		return 1;
	return 0;

}

//==============================================================================

int True(const struct SStudent *s, float nAvr)
{
	return 1;
}

//==============================================================================

int MakeRow(FILE *pFile, struct SStudent *s, char *str)
{
	char *token = strtok(str, " \n");
	if (token == NULL || (strlen(token) / 2 > nSurnamenSize))
		return 1;							//fill given SStudent structure
	strcpy(s->szSurname, token);
	token = strtok(NULL, " \n");
	if (token == NULL || (strlen(token) / 2 > nNamenSize))
		return 1;
	strcpy(s->szName, token);

	for(int j = 0; j < nDateElements; j++){
		token = strtok(NULL, " .\n");
		if (token == NULL)
			return 1;
		int n = atoi(token);
		if (j == 2){
			if (n < 1)
				return 1;
		}else{
			if (n < 1 || n > 12)
				return 1;
		}
		s->nBirthdate[j] = n;
	}

	for(int j = 0; j < nExamGradesAmount; j++){
		token = strtok(NULL, " \n");
		if (token == NULL)
			return 1;
		int n = atoi(token);
		if (n < 2 || n > 5)
			return 1;
		s->nExamGrade[j] = n;
	}
	return 0;
}

//==============================================================================

struct SStudent *ReadRow(FILE *pFile, struct SStudent *pArr, int *nSize)
{
	char str[200] = "";
	if(fgets(str, 200, pFile) == NULL)
		return NULL;
	pArr = realloc(pArr, (*nSize + 1) * sizeof(struct SStudent));
	int err = MakeRow(pFile, &pArr[*nSize], str);
	if(err){
		printf("Student data was incorrect\n");
		*nSize -= 1;
	}
	*nSize += 1;
	return pArr;
}

//==============================================================================

struct SStudent *ReadList(FILE *pFile, struct SStudent *pArr, int *nSize)
{
	struct SStudent *s;
	while(1){
		s = ReadRow(pFile, pArr, nSize);
		if (s == NULL)
			return pArr;
		pArr = s;
	}
}
