#include <stdio.h>

#include "student.h"
#include "table.h"
#include "sort.h"

#define LIST_SIZE 27

int main()
{
	FILE *f;
	struct student arr[LIST_SIZE]; 

	f = fopen("list.txt", "r");
	ReadList(f, arr, LIST_SIZE);
	fclose(f);

	//PrintTable(stdout, arr, LIST_SIZE, True, 0);
	f = fopen("unsorted.txt", "w");
	PrintTable(f, arr, LIST_SIZE, True, 0);
	fclose(f);

	SortArray(arr, LIST_SIZE, AgeUp);

	f = fopen("sorted.txt", "w");
	PrintTable(f, arr, LIST_SIZE, True, 0);
	fclose(f);

	float avr = AverageRating(arr, LIST_SIZE);

	f = fopen("SortedWithRating.txt", "w");
	PrintTable(f, arr, LIST_SIZE, isGreaterThanAverageRating, avr);
	fclose(f);

	return 0;
}
