#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "table.h"
#include "linked.h"

//==============================================================================

struct SItem *MakeLinkedList(struct SStudent pArr[], int nSize)
{
	struct SItem *pFirst = NULL, *pLast = NULL, *tmp;
	for(int i = 0; i < nSize; i++){
		tmp = malloc(sizeof(struct SItem));
		tmp->SStudent = pArr[i];
		tmp->pNext = NULL;
		if(pLast){
			pLast->pNext = tmp;
			pLast = pLast->pNext;
		}else{
			pFirst = pLast = tmp;
		}
	}
	return pFirst;
}

//==============================================================================

void PrintLinkedListTable(FILE *pFile, const struct SItem *pFirst)
{
	fprintf(pFile, "-----------------------------------------------"\
			   "-------------------------------\n");
	fprintf(pFile, "|    |               |           |    Дата    |"\
			   " Список екзаменаційних оцінок |\n");
	fprintf(pFile, "| №  |   Прізвище    |   Ім'я    |            |"\
			   "------------------------------|\n");
	fprintf(pFile, "|    |               |           | народження |"\
			   " ОП | КДМ  | MA | ЛААГ | Іст. |\n");
	fprintf(pFile, "-----------------------------------------------"\
			   "-------------------------------\n");
	struct SItem *tmp = pFirst;
	for(int i = 0; tmp; i++){
		PrintRow(pFile, &tmp->SStudent, i + 1);
		tmp = tmp->pNext;
	}
	fprintf(pFile, "-----------------------------------------------"\
			   "-------------------------------\n");
}

//==============================================================================

void InsertIntoLinkedList(struct SItem **pp, struct SStudent *s,
		int (*cond)(struct SStudent*, struct SStudent*))
{
	while(*pp && cond(s, &(*pp)->SStudent))
		pp = &(*pp)->pNext;
	struct SItem *tmp = malloc(sizeof(struct SItem));
	tmp->pNext = *pp;
	tmp->SStudent = *s;
	*pp = tmp;
}

//==============================================================================

void RemoveFromLinkedList(struct SItem **pp,
	int (*cond)(struct SStudent*))
{
	while(*pp){
		if(cond(&(*pp)->SStudent)){
			struct SItem *tmp = *pp;
			*pp = (*pp)->pNext;
			free(tmp);
		}else{
			pp = &(*pp)->pNext;
		}
	}
}

//==============================================================================

int LLTrue(struct SStudent *s)
{
	return 1;
}

//==============================================================================

int HasNoFive(struct SStudent *s)               //returns TRUE if student doesn't
{												//have a five grade
	for(int i = 0; i < nExamGradesAmount; i++)
		if(s->nExamGrade[i] == 5)
			return 0;
	return 1;
}

int HasGradeGreaterThan3(struct SStudent *s)
{
	for(int i = 0; i < nExamGradesAmount; i++)
		if(s->nExamGrade[i] < 3)
			return 0;
	return 1;
}
