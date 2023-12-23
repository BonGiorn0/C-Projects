#include <stdio.h>
#include <string.h>
                                                                            
#include "student.h"
#include "sort.h"
#include "table.h"
#include "linked.h"

 
int main()
{
	FILE *pFile;
    //struct SStudent smb = {"Моставчук", "Петро", {12, 12, 2000}, {5, 4, 5, 5, 5}};
    struct SStudent *pArr = NULL;
	struct SItem *ll = NULL;
	int size = 0;

    pFile = fopen("exceptive.txt", "r");
    pArr = ReadList(pFile, pArr, &size);
    fclose(pFile);

	printf("Enter a student:\n");
	ReadRow(stdin, pArr, &size);

    SortArray(pArr, size, AgeUp);

	ll = MakeLinkedList(pArr, size);

	//InsertIntoLinkedList(&ll, &smb, AgeUp);

	//RemoveFromLinkedList(&ll, HasNoFive);

	//InsertIntoLinkedList(&ll, &smb, AgeUp);

    pFile = fopen("no5.txt", "w");
	PrintLinkedListTable(stdout, ll);
    fclose(pFile);

	printf("%d", strlen("фіва"));

	return 0;
}

