#include <stdio.h>
#include "graph.h"

enum{
    GraphSize = 6
};

void Warshall(int res[][GraphSize][GraphSize])
{
    for(int k = 0; k < GraphSize; k++)
        for(int i = 0; i < GraphSize; i++)
            for(int j = 0; j < GraphSize; j++)
                res[k + 1][i][j] = res[k][i][j] ||
                                   res[k][i][k] &&
                                   res[k][k][j];
}

int main(int argc, char *argv[])
{
    int G[GraphSize][GraphSize] ={  {0, 1, 1, 0, 0, 0},                     
                                    {0, 0, 1, 1, 0, 0},
                                    {0, 0, 0, 1, 1, 1},
                                    {0, 0, 0, 0, 1, 0},
                                    {0, 1, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0, 0},
                                  };

    int m[GraphSize + 1][GraphSize][GraphSize] = {0};
    int adj[GraphSize][GraphSize] = {0};
    CopyMatrix(m[0], G, GraphSize);

    for(int i = 1; i < GraphSize; ++i){
        MultMatrix(m[i], m[i - 1], G, GraphSize);
        AddMatrix(adj, adj, m[i], GraphSize);
    }
    //PrintMatrix(m[argv[1][0] - '0'], GraphSize);
    PrintMatrix(adj, GraphSize);

    int n[GraphSize][GraphSize][GraphSize] = {0};
    CopyMatrix(n[0], G, GraphSize);
    Warshall(n);
    //PrintMatrix(n[argv[1][0] - '0'], GraphSize);
    PrintMatrix(n[GraphSize], GraphSize);

    return 0;
}


