#include <stdio.h>
#include "graph.h"

//

void AddMatrix(int res[], int a[], int b[], int size)           
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            res[i * size + j] = a[i * size + j] || b[i * size + j];
}
 
void MultMatrix(int res[], int a[], int b[], int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            for(int k = 0; k < size; k++)
                res[i * size + j] = res[i * size + j] ||
                                      a[i * size + k] &&
                                      b[k * size + j];
}

void PrintMatrix(int g[], int size)
{
    for(int i = 0; i < size; i++){
        printf("\n");
        for(int j = 0; j < size; j++)
            printf("%d ", g[i * size + j]);
    }
    printf("\n");
}

void CopyMatrix(int res[], int g[], int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            res[i * size + j] = g[i * size + j];
}

void ConstructComplementary(int res[], int g[], int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++){
            if (i == j)
                continue;
            res[i * size + j] = !g[i * size + j];
        }
}

void ConstructUnion(int res[],int G[],int H[], int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++){
            if (i == j)
                continue;
            res[i * size + j] = G[i * size + j] || H[i * size + j];
        }
}

void ConstructCrossing(int res[], int G[], int H[], int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++){
            if (i == j)
                continue;
            U[i * size + j] = G[i * size + j] && H[i * size + j];
        }
}

int isUndirected(int G[], int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(G[i * size + j] != G[j * size + i])
                return 0;
    return 1;
}

int CountEdges(int G[], int size)
{
    int res = 0;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(G[i * size + j])
                res++;
    if(isUndirected(G, size))
        return res / 2;
    return res;
}
