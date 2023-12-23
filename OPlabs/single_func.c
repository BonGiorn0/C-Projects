#include "single_func.h"


void ListInit(struct Node ** ppHead){
    *ppHead = NULL;
}


int IsListEmpty(struct Node * pHead){
    return NULL == pHead;
}

int AddToEndList(struct Node ** ppHead, struct Node * pElem){
    if(!pElem)
    {
        return -1;
    }
    
    if(IsListEmpty(*ppHead))
    {
        *ppHead = pElem;
        pElem->pNext = NULL;
    }
    else
    {
        struct Node * pTemp = *ppHead;
        
        while (pTemp->pNext != NULL) {
            pTemp = pTemp->pNext;
        }
        
        pTemp->pNext = pElem;
        pElem->pNext = NULL;
    }
    
    return 0;
}

int FileScan(char * filename, struct Node ** ppHead){
    FILE * pF;
    pF = fopen(filename, "rt");
    
    if(pF == NULL)
        {
            printf("Error open file\n");
        }
    
    char str[1000];
    char * ptr;

    int count = 0;
    while (!feof(pF)) {
            
        fgets(str, 1000, pF);
            
        struct Node * pElem = malloc(sizeof(struct Node));
        ptr = strtok(str , ",\n");
        strcpy(pElem->value.surname, ptr);

        ptr = strtok(NULL , ",");
        strcpy(pElem->value.name, ptr);

        ptr = strtok(NULL , ".");
        pElem->value.day = atoi(ptr);

        ptr = strtok(NULL , ".");
        pElem->value.month = atoi(ptr);

        ptr = strtok(NULL , ",");
        pElem->value.year = atoi(ptr);

        for(int j = 0; j < 6; j++){
            ptr = strtok(NULL, " ");
            pElem->value.grades[j] = atoi(ptr);
        }
            
        AddToEndList(ppHead, pElem);
        count ++;
             
        }
    return count;
}

void PrintList(struct Node * pHead){
    printf("----------------------------------------------------------------\n");
    printf("|  surname & name   | date of birthday |         marks         |\n");
    printf("----------------------------------------------------------------\n");
           
        
    struct Node * pTemp = pHead;
    while (pTemp) {
        printf("| %s %s \t|    %02d.%02d.%d    | %d | %d | %d | %d | %d | %d |\n", pTemp->value.surname, pTemp->value.name, pTemp->value.day, pTemp->value.month, pTemp->value.year, pTemp->value.grades[0], pTemp->value.grades[1], pTemp->value.grades[2], pTemp->value.grades[3], pTemp->value.grades[4], pTemp->value.grades[5]);
        printf("----------------------------------------------------------------\n");
        pTemp = pTemp->pNext;
    }
}


void SwapFirstElemList(struct Node ** ppHead){
    struct Node * pTemp1 = *ppHead;
    struct Node * pTemp2 = (*ppHead)->pNext;
    struct Node * pTemp3 = (*ppHead)->pNext->pNext;
    
    *ppHead = pTemp2;
    pTemp2->pNext = pTemp1;
    pTemp1->pNext = pTemp3;

    pTemp1 = pTemp2;
}

void SwapMiddleElemList(struct Node ** ppElem1, struct Node ** ppElem2, struct Node * pHead){
    
    struct Node * pTemp1 = *ppElem1;
    struct Node * pTemp2 = *ppElem2;
    struct Node * pTemp3 = (*ppElem2)->pNext;
    
    
    struct Node * pPrev = pHead;
    while (pPrev->pNext != *ppElem1) {
        pPrev = pPrev->pNext;
    }
    
    pTemp2->pNext = pTemp1;
    pTemp1->pNext = pTemp3;
    pPrev->pNext = pTemp2;
    
    pTemp1 = pTemp2;
}

void SwapLastElemList(struct Node ** ppElem1, struct Node ** ppElem2, struct Node * pHead){
    struct Node * pTemp1 = *ppElem1;
    struct Node * pTemp2 = *ppElem2;
    
    
    struct Node * pPrev = pHead;
    while (pPrev->pNext != *ppElem1) {
        pPrev = pPrev->pNext;
    }
    
    pTemp2->pNext = pTemp1;
    pTemp1->pNext = NULL;
    pPrev->pNext = pTemp2;
    
    pTemp1 = pTemp2;
}


void SearchTwoOldestStudentsInList(struct Node ** ppHead, int count){
    struct Node * pTemp1 = *ppHead;
    struct Node * pTemp2 = pTemp1->pNext;
    
    for(int i = 0; i < count; i ++){
        for(;  pTemp1->pNext != NULL; pTemp1 = pTemp2,
            pTemp2 = pTemp2->pNext){
            if(pTemp1->value.year > pTemp2->value.year)
            {
                if(pTemp1 == *ppHead)
                {
                    SwapFirstElemList(ppHead);
                    pTemp1 = *ppHead;
                    pTemp2 = pTemp1->pNext;
                }
                else if (pTemp1 != *ppHead && pTemp2->pNext != NULL)
                {
                    SwapMiddleElemList(&pTemp1, &pTemp2, *ppHead);
                    pTemp1 = pTemp2;
                    pTemp2 = pTemp2->pNext;
                }
                else if (pTemp2->pNext == NULL)
                {
                    SwapLastElemList(&pTemp1, &pTemp2, *ppHead);
                    pTemp1 = pTemp2;
                    pTemp2 = pTemp2->pNext;
                }
            }
        }
        pTemp1 = *ppHead;
        pTemp2 = pTemp1->pNext;
    }
    
    for(int i = 0; i < count; i ++){
        for(;  pTemp1->pNext != NULL; pTemp1 = pTemp2,
            pTemp2 = pTemp2->pNext){
            if(pTemp1->value.year == pTemp2->value.year && pTemp1->value.month > pTemp2->value.month)
            {
                if(pTemp1 == *ppHead)
                {
                    SwapFirstElemList(ppHead);
                    pTemp1 = *ppHead;
                    pTemp2 = pTemp1->pNext;
                }
                else if (pTemp1 != *ppHead && pTemp2->pNext != NULL)
                {
                    SwapMiddleElemList(&pTemp1, &pTemp2, *ppHead);
                    pTemp1 = pTemp2;
                    pTemp2 = pTemp2->pNext;
                }
                else if (pTemp2->pNext == NULL)
                {
                    SwapLastElemList(&pTemp1, &pTemp2, *ppHead);
                    pTemp1 = pTemp2;
                    pTemp2 = pTemp2->pNext;
                }
            }
        }
        pTemp1 = *ppHead;
        pTemp2 = pTemp1->pNext;
    }
    
    for(int i = 0; i < count; i ++){
        for(;  pTemp1->pNext != NULL; pTemp1 = pTemp2,
            pTemp2 = pTemp2->pNext){
            if(pTemp1->value.year == pTemp2->value.year && pTemp1->value.month == pTemp2->value.month && pTemp1->value.day > pTemp2->value.day)
            {
                if(pTemp1 == *ppHead)
                {
                    SwapFirstElemList(ppHead);
                    pTemp1 = *ppHead;
                    pTemp2 = pTemp1->pNext;
                }
                else if (pTemp1 != *ppHead && pTemp2->pNext != NULL)
                {
                    SwapMiddleElemList(&pTemp1, &pTemp2, *ppHead);
                    pTemp1 = pTemp2;
                    pTemp2 = pTemp2->pNext;
                }
                else if (pTemp2->pNext == NULL)
                {
                    SwapLastElemList(&pTemp1, &pTemp2, *ppHead);
                    pTemp1 = pTemp2;
                    pTemp2 = pTemp2->pNext;
                }
            }
        }
        pTemp1 = *ppHead;
        pTemp2 = pTemp1->pNext;
    }
    
    printf("\nДва найстарші студенти, які не отримали 2 на першому іспиті:\n");
        printf("%s %s та %s %s\n\n", (*ppHead)->value.surname,(*ppHead)->value.name, (*ppHead)->pNext->value.surname, (*ppHead)->pNext->value.name);
}


 
void SortSurnameAlpha(struct Node ** ppHead, int count){
    struct Node * pTemp1 = *ppHead;
    struct Node * pTemp2 = pTemp1->pNext;
    
    for(int i = 0; i < count; i ++){
        for(;  pTemp2->pNext != NULL; pTemp1 = pTemp2,
            pTemp2 = pTemp2->pNext){
            if(strcmp(pTemp1->value.surname, pTemp2->value.surname) > 0)
            {
                if(pTemp1 == *ppHead)
                {
                    SwapFirstElemList(ppHead);
                    pTemp1 = *ppHead;
                    pTemp2 = pTemp1->pNext;
                }
                else if (pTemp1 != *ppHead && pTemp2->pNext != NULL)
                {
                    SwapMiddleElemList(&pTemp1, &pTemp2, *ppHead);
                    pTemp1 = pTemp2;
                    pTemp2 = pTemp2->pNext;
                }
                else if (pTemp2->pNext == NULL)
                {
                    SwapLastElemList(&pTemp1, &pTemp2, *ppHead);
                    pTemp1 = pTemp2;
                    pTemp2 = pTemp2->pNext;
                }
            }
        }
        pTemp1 = *ppHead;
        pTemp2 = pTemp1->pNext;
    }
}


void InsertElemToStart(struct Node ** ppHead, struct Node * pElem){
    if(ppHead == NULL || pElem == NULL)
    {
        printf("Error insrert");
    }
    pElem->pNext = *ppHead;
    *ppHead = pElem;
}

void InsertElemBetween(struct Node * pTemp1, struct Node * pTemp2, struct Node * pElem){
    if(pTemp1 == NULL || pElem == NULL || pTemp2 == NULL)
    {
        printf("Error insrert");
    }
    pTemp1->pNext = pElem;
    pElem->pNext = pTemp2;
    
}


void SearchPosAndInsertElem(struct Node ** ppHead, struct Node ** ppElem){
    struct Node * pTemp1 = *ppHead;
    struct Node * pTemp2 = pTemp1->pNext;
    
    for(;  pTemp1->pNext != NULL; pTemp1 = pTemp2, pTemp2 = pTemp2->pNext){
        if(strcmp(pTemp1->value.surname, (*ppElem)->value.surname) < 0 && strcmp(pTemp2->value.surname, (*ppElem)->value.surname) > 0)
        {
            InsertElemBetween(pTemp1, pTemp2, *ppElem);
            break;
        }
        else if (strcmp(pTemp1->value.surname, (*ppElem)->value.surname) > 0)
        {
            InsertElemToStart(ppHead, *ppElem);
            break;
        }
        else if (strcmp(pTemp2->value.surname, (*ppElem)->value.surname) < 0 && pTemp2->pNext == NULL)
        {
            AddToEndList(ppHead, *ppElem);
            break;
        }
        
    }
}


void AddNewElemToList(struct Node ** ppHead, int * count){
   
    int pool = 0;
    do{
        printf("\nEnter non-zero if you want to add a new element to list, or enter zero if you want to rest: ");
        scanf("%d", &pool);
       
        if(pool != 0)
        {
            char str[100];
            int info;
            
            struct Node * pElem = malloc(sizeof(struct Node));
            
            printf("Surname: ");
            scanf("%s", str);
            strcpy(pElem->value.surname, str);
            
            printf("Name: ");
            scanf("%s", str);
            strcpy(pElem->value.name, str);
            
            printf("Day: ");
            scanf("%d", &info);
            pElem->value.day = info;
            
            printf("Month: ");
            scanf("%d", &info);
            pElem->value.month = info;
            
            printf("Year: ");
            scanf("%d", &info);
            pElem->value.year = info;
            
            for(int j = 0; j < 6; j++){
                printf("Grade #%d: ", j+1);
                scanf("%d", &info);
                pElem->value.grades[j] = info;
            }
            
            SearchPosAndInsertElem(ppHead, &pElem);
            (*count) ++;
        }
        
        else
        {
            break;
        }
            
    } while(1);
    
}

void DeleteFirstElem(struct Node ** pHead){
    if(*pHead == NULL)
    {
        printf("Error insrert");
    }
    *pHead = (*pHead)->pNext;
}


void DeleteLastElem(struct Node ** pLast, struct Node * pHead){
    if(*pLast == NULL || pHead == NULL)
    {
        printf("Error insrert");
    }
    
    struct Node * pPrev = pHead;
    while (pPrev->pNext != *pLast) {
        pPrev = pPrev->pNext;
    }
    pPrev->pNext = NULL;
    free(*pLast);
}


void DeleteStudentsInsideList(struct Node ** pDelete, struct Node * pHead){
    if(*pDelete == NULL || pHead == NULL)
    {
        printf("Error insrert");
    }
    
    struct Node * pPrev = pHead;
    while (pPrev->pNext != *pDelete) {
        pPrev = pPrev->pNext;
    }
    struct Node * pAfter = (*pDelete)->pNext;
    pPrev->pNext = pAfter;
    
}


void DeleteBadStudents(struct Node ** ppHead, int count){
    struct Node * pTemp = *ppHead;
        for(int i = 0; i < count; pTemp = pTemp->pNext, i++) {
            if(pTemp->value.grades[0] == 2)
            {
                if(pTemp == *ppHead)
                {
                    DeleteFirstElem(ppHead);
                }
                else if (i == count-1)
                {
                    DeleteLastElem(&pTemp, *ppHead);
                    
                }
                else
                {
                    DeleteStudentsInsideList(&pTemp, *ppHead);
                }
            }
    }
}


