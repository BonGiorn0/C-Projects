#include <stdio.h>

enum{
	size = 5
};

int Kruskal(int G[][size])
{
    int v[size] = {0};
    int minId = 0, minRow = 0, res = 0;
	for(int k = 0; k < size - 1; k++){
		int min = (unsigned short)(-1) / 2;
		for(int i = 0; i < size; i++){
			for(int j = i + 1; j < size; j++){
				if (v[j] && v[j - 1])
					continue;
				if (G[i][j] < min){
					min = G[i][j];
					minId = j;
					minRow = i;
				}
			}
		}
		G[minRow][minId] = (unsigned short)(-1) / 2;
		res += min;
		v[minId] = 1;
		printf("%c%c ", 'a' + minRow, 'a' + minId);
	}
    return res; 
}

int main()
{
	int G[size][size] = {
		{0 , 6 , 3 , 10, 7 },
		{6 , 0 , 1 , 2 , 3 },
		{3 , 1 , 0 , 5 , 6 },
		{10, 2 , 5 , 0 , 3 },
		{7 , 3 , 6 , 3 , 0 }
	};

	int res = Kruskal(G);
	printf("\n%d\n", res);

}
