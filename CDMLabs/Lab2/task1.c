#include <stdio.h>
#include "graph.h"

enum{
    GraphSize = 6
};


int main(){
    int G[GraphSize][GraphSize] =  {{0, 0, 1, 0, 1, 1},
                                    {0, 0, 0, 1, 0, 1},
                                    {1, 0, 0, 0, 1, 0},
                                    {0, 1, 0, 0, 0, 1},
                                    {1, 0, 1, 0, 0, 0},
                                    {1, 1, 0, 1, 0, 0}
                                    };
    int H[GraphSize][GraphSize] =  {{0, 1, 0, 0, 0, 0},
                                    {1, 0, 1, 1, 1, 0},
                                    {0, 1, 0, 0, 1, 0},
                                    {0, 1, 0, 0, 1, 0},
                                    {0, 1, 1, 1, 0, 1},
                                    {0, 0, 0, 0, 1, 0}
                                    };

    int GC [GraphSize][GraphSize] = {0};
    int U [GraphSize][GraphSize] = {0};
    int X [GraphSize][GraphSize] = {0};

    ConstructComplementary(GC, G, GraphSize);
    ConstructUnion(U, G, H, GraphSize);
    ConstructCrossing(X, G, H, GraphSize);

    printf("_\n");
    printf("G:\n");
    printf("Verticies: %d, edges: %d", 
            GraphSize, CountEdges(GC, GraphSize));
    PrintGraph(GC, GraphSize);
    printf("\nG ∪ H:\n");
    printf("Verticies: %d, edges: %d", 
            GraphSize, CountEdges(U, GraphSize));
    PrintGraph(U, GraphSize);
    printf("\nG ⋂  H:\n");
    printf("Verticies: %d, edges: %d", 
            GraphSize, CountEdges(X, GraphSize));
    PrintGraph(X, GraphSize);

    return 0;

}
