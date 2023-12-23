#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.h"

enum{
    infinity = 99999,
};


void PrintPseudoMatrix(const struct node v[] , int n, int m)
{
    for(int i = 0; i < n; i++){
        printf("\n");
        for(int j = 0; j < m; j++)
            printf("%d ", v[i * n + j].distance);
    }
    printf("\n");

}

void PrintMatrix(const int **g, int n, int m)
{
    for(int i = 0; i < n; i++){
        printf("\n");
        for(int j = 0; j < m; j++)
            printf("%d ", g[i][j]);
    }
}

void PrintArray(const int *g, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", g[i]);
    printf("\n");
}

void CreateGraph(int **g, int n, int m)
{
    for(int i = 0; i < n * m; i++)
        AddGraphVertex(g, i, n, m);
}

void AddGraphVertex(int **g, int v, int n, int m)
{
    for(int j = 0; j < n * m; j++){
        if (
        //commented lines used for diagonal conections 
        //j == i - m - 1  || 
        j == v - m      || 
        //j == i - m + 1  || 
        j == v - 1      || 
        j == v + 1      || 
        //j == i + m - 1  || 
        j == v + m      //|| 
        //j == i + m + 1 
        )
            g[v][j] = 1;
        else
            g[v][j] = infinity;
        if ( n != 1 && (
                (j % m == 0 && v == j - 1)        ||
                (v % m == 0 && j == v - 1)        || 
                (j % m == 0 && (v + 1) % m == 0)  ||
                (v % m == 0 && (j + 1) % m == 0)
             )
        )
            g[v][j] = infinity;
    }
}

void DeleteGraphVertex(int **g, int v, int n, int m)
{
    for(int i = 0; i < n * m; i++){
        g[v][i] = infinity;
        g[i][v] = infinity;
    }
}

void VertexInit(struct node *v, const int **g,
        int n, int src, int end)
{
    for (int i = 0; i < n; i++) {
      v[i].distance = g[src][i];
      v[i].prev = src;
      v[i].visited = 0;
      v[i].isSrc = 0;
      v[i].isEnd = 0;
      //v[i].isWall = 0;
    }

    v[src].distance = 0;
    v[src].visited = 1;
    v[src].isSrc = 1;

    v[end].isEnd = 1;
}

int Dijkstra(struct node v[], const int **cost, 
        int n, int *nextnode){
    int mindistance = infinity;

    for (int j = 0; j < n; j++)
      if (!v[j].visited && v[j].distance < mindistance) {
        mindistance = v[j].distance;
        *nextnode = j;
      }

    if (v[*nextnode].isEnd)
        return 0;

    v[*nextnode].visited = 1;
    for (int j = 0; j < n; j++)
      if (!v[j].visited)
        if (mindistance + cost[*nextnode][j] <= v[j].distance) {
          v[j].distance = mindistance + cost[*nextnode][j];
          v[j].prev = *nextnode;
        }
    return 1;
}
