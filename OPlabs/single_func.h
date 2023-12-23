#ifndef single_func_h
#define single_func_h
#define L 20

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Students {
    char surname[L];
    char name[L];
    int day;
    int month;
    int year;
    int grades[6];
} people;

struct Node {
    people value;
    struct Node * pNext;
};



void ListInit(struct Node ** ppHead);
int IsListEmpty(struct Node * pHead);
int AddToEndList(struct Node ** ppHead, struct Node * pElem);
int FileScan(char * filename,  struct Node ** pHead);
void PrintList(struct Node * pHead);
void SwapFirstElemList(struct Node ** ppHead);
void SwapMiddleElemList(struct Node ** ppElem1, struct Node ** ppElem2, struct Node * pHead);
void SortSurnameAlpha(struct Node ** ppHead, int count);
void SwapLastElemList(struct Node ** ppElem1, struct Node ** ppElem2, struct Node * pHead);
void SearchTwoOldestStudentsInList(struct Node ** ppHead, int count);
void AddNewElemToList(struct Node ** ppHead, int * count);
void SearchPosAndInsertElem(struct Node ** ppHead, struct Node ** ppElem);
void InsertElemToStart(struct Node ** ppHead, struct Node * pElem);
void InsertElemBetween(struct Node * pTemp1, struct Node * pTemp2, struct Node * pElem);
void DeleteFirstElem(struct Node ** pHead);
void DeleteLastElem(struct Node ** pLast, struct Node * pHead);
void DeleteStudentsInsideList(struct Node ** pDelete, struct Node * pHead);
void DeleteBadStudents(struct Node ** ppHead, int count);


#endif
