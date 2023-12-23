#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GRADES 3
#define STUDENTS 4

struct Students {
    char lastName[20];
    char name[30];
    char date[20];
    int grade[GRADES];
    double average;
}stud[STUDENTS + 1], newStud;

struct item {
    struct Students person;
    struct item* next;
};

int main() {
    FILE* file = fopen("Students.txt", "r");
    if (file == NULL) {
        return -1;
    }
    int ch = 0;
    int i = 0;
    while (ch != EOF) {
        fscanf(file, "%s", stud[i].lastName);
        fscanf(file, "%s", stud[i].name);
        fscanf(file, "%s", stud[i].date);
        for (int j = 0; j < GRADES; j++) {
            fscanf(file, "%d", &stud[i].grade[j]);
        }
        ch = getc(file);
        i++;
    }fclose(file);

    for (int c = 0; c < STUDENTS; c++) {
        double sum = 0;
        for (int z = 0; z < GRADES; z++) {
            sum += stud[c].grade[z];
        }
        stud[c].average = sum / GRADES;
    }

    for (int i = 0; i < STUDENTS - 1; i++) {
        for (int j = 0; j < STUDENTS - 1 - i; j++) {
            if (stud[j].average > stud[j + 1].average) {
                stud[STUDENTS] = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = stud[STUDENTS];
            }
        }
    }

    printf("\tResults:\n ");
    for (int x = 0; x < STUDENTS; x++) {
        printf("%s %s %lf\n ", stud[x].lastName, stud[x].name, stud[x].average);
    }

    struct item* ptr = (struct item*)malloc(sizeof(struct item));
    struct item* start = NULL;
    for(int i = 0; i < STUDENTS; i++){
        ptr->person = stud[i];
        if (!start) 
            start = ptr;
        if (!(i == STUDENTS - 1)){
            struct item* ptrptr = (struct item*)malloc(sizeof(struct item));
            ptr->next = ptrptr;
            ptr = ptrptr;
        }
    }
    ptr->next = NULL;

    ptr = start;

    while (ptr != NULL) {
        printf("\n%s %s %lf", ptr->person.lastName, ptr->person.name, ptr->person.average);
        ptr = ptr->next;
    }

    printf("\nEnter last name of new student: ");
    scanf("%s", newStud.lastName);
    printf("Enter the name of new student: ");
    scanf("%s", newStud.name);
    printf("Enter the date of birth of new student: ");
    scanf("%s", newStud.date);
    printf("Enter the list of grades of new student: ");
    for (int i = 0; i < GRADES; i++) {
        scanf("%d", &newStud.grade[i]);
    }
    double summa = 0;
    for (int z = 0; z < GRADES; z++) {
        summa += newStud.grade[z];
    }
    newStud.average = summa / GRADES;


    struct item* newNode = (struct item*)malloc(sizeof(struct item));
    newNode->person = newStud;
    newNode->next = NULL;

    ptr = start;

    if (ptr == NULL || ptr->person.average > newStud.average) {
        newNode->next = start;
        start = newNode;
    }else {
        while (ptr->next != NULL && ptr->person.average < newNode->person.average)
            ptr = ptr->next;

        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    ptr = start;
    while (ptr != NULL) {
        printf("\n%s %s %lf", ptr->person.lastName, ptr->person.name, ptr->person.average);
        ptr = ptr->next;
    }

    //Deleting
    ptr = start;
    while (1) {
        struct item* ptrptr = ptr;
        ptr = ptr->next;
        if (!ptr)  break;
        int count = 0;
        for (int i = 0; i < GRADES; i++) {
            if (ptr->person.grade[i] == 2) {
                count++;
            }
        }

        if (count == 2) {
            if (!ptr->next) {
                ptrptr->next == NULL;
                break;
            }
            ptrptr->next = ptr->next;
            free(ptr);
            ptr = ptrptr;
        }
    }

    ptr = start;
    int count = 0;
    for (int i = 0; i < GRADES; i++) {
        if (ptr->person.grade[i] == 2) {
            count++;
        }
    }
    if (count == 2) {
        if (ptr->next)
            start = ptr->next;
        else start = NULL;
    }

    printf("\n");

    ptr = start;
    while (ptr->next != NULL) {
        printf("\n%s %s %lf", ptr->person.lastName, ptr->person.name, ptr->person.average);
        ptr = ptr->next;
    }

    return 0;
}
