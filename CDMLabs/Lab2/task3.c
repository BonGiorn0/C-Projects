#include <stdio.h>

enum{
    GraphSize = 8
};

int notPassed(int v[])
{
    for(int i = 0; i < GraphSize; i++)
        if (!v[i])
            return 1;
    return 0;
}

int ShortestRoute(int G[][GraphSize])
{
    int v[GraphSize] = {0};
    v[0] = 1;
    int minId = 0, i = 0, res = 0;
    printf("a-");
    while (notPassed(v)){
        int min = (unsigned short)(-1) / 2;
        for(int j = 0; j < GraphSize; j++){
            if (i == j || v[j])
                continue;
            if (G[i][j] < min){
                min = G[i][j];
                minId = j;
            }
        }
        res += min;
        v[minId] = 1;
        i = minId;
        printf("%c-", 'a' + minId);
    }
    printf("a\n");
    return res + G[i][0]; 
}

int main()
{
    int G[GraphSize][GraphSize] = { {0, 1, 3, 1, 2, 1, 3, 2},
                                    {1, 0, 6, 4, 2, 1, 1, 2},
                                    {3, 6, 0, 1, 6, 1, 2, 3},
                                    {1, 4, 1, 0, 5, 2, 2, 5},
                                    {2, 2, 6, 5, 0, 6, 6, 6},
                                    {1, 1, 1, 2, 6, 0, 1, 5},
                                    {3, 1, 2, 2, 6, 1, 0, 5},
                                    {2, 2, 3, 5, 6, 5, 5, 0},
                                  };  
    printf("The length of shortest Hamiltons cycle is: %d\n",
                                                    ShortestRoute(G));
    return 0;
}
