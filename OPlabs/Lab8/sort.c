#include <string.h>
#include <stdlib.h>

#include "student.h"
#include "sort.h"

void swap(struct student *a, struct student *b)
{
	struct student tmp = *a;
	*a = *b;
	*b = tmp;
}

void SortArray(struct student arr[], int size,
		int (*condition)(struct student*, struct student*))
{
	for(int i = 0; i < size - 1; i++)
		for(int j = 0; j < size - i - 1; j++)
			if(condition(&arr[j], &arr[j + 1]))
				swap(&arr[j], &arr[j + 1]);
}

int AgeUp(struct student *a, struct student *b)
{
    char strA[100];
    char strB[100];
    strcpy(strA, a->birthdate);
    strcpy(strB, b->birthdate);

    char *token = strtok(strA, ".");
    int age1 = 10 * atoi(token);
    token = strtok(NULL, ".");
    age1 += 100 * atoi(token);
    token = strtok(NULL, ".");
    age1 += 10000 * atoi(token);

    token = strtok(strB, ".");
    int age2 = 10 * atoi(token);
    token = strtok(NULL, ".");
    age2 += 100 * atoi(token);
    token = strtok(NULL, ".");
    age2 += 10000 * atoi(token);

    if(age1 < age2)
        return 1;
    return 0;
}             
