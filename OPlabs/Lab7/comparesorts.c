#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100000

void FillArrays(int x1[], int x2[], int len)
{
    for(int i = 0; i < len; ++i)
        x1[i] = x2[i] = 1 + (int)(100.0 * rand() / (RAND_MAX + 1.0));
}

void PrintArray(int x[], int len)
{
    for(int i = 0; i < len; ++i)
        printf("%2d ", x[i]);
    printf("\n");
}

int isSorted(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;
    return 1;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (1){
        do {
            i++;
        } while (a[i] < pivot);
 
        do {
            j--;
        } while (a[j] > pivot);
 
        if (i >= j) {
            return j;
        }
 
        swap(&a[i], &a[j]);
    }
}

void quicksort(int a[], int low, int high)
{
    if (low >= high) {
        return;
    }
 
    int pivot = partition(a, low, high);
    quicksort(a, low, pivot);
    quicksort(a, pivot + 1, high);
}

void bubblesort(int a[], int useless, int len)
{
    for(int i = 0; i < len; ++i)
        for(int j = 0; j < len - i - 1; ++j)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}

double DurationCheck(void (*func)(int*, int, int), int x[], int len)
{
    clock_t start, end;
    start = clock();
    func(x, 0, len);
    end = clock();
    return ((double)(end - start) / CLOCKS_PER_SEC);
}

int main(){
    int a1[SIZE] = {0}, a2[SIZE] = {0};

    FillArrays(a1, a2, SIZE);

    printf("The program sorts an array of %d elements\n", SIZE);
    printf("The time of quicksort is %lf sec\n",
            DurationCheck(quicksort, a1, SIZE - 1));
    printf("The time of bubblesort is %lf sec\n",
            DurationCheck(bubblesort, a2, SIZE));

    if(isSorted(a1, SIZE))
        printf("First array is sorted\n");
    if(isSorted(a2, SIZE))
        printf("Second array is sorted\n");

    return 0;
}
