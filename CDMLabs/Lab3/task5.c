#include <stdio.h>

#include "graph.h"

enum{
	size = 4
};

void MakeMatrix(int res[size][size], int r[][2])
{
	for(int i = 0; i < 8; i++)
		res[r[i][0] - 1][r[i][1] - 1] = 1;
}

int isTransitive(const int r[size][size])
{
	int square[size][size] = {0};
	MultMatrix(square, r, r, size);
	int isTransitive = 1, isAntitransitive = 1; 

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(!(r[i][j] >= square[i][j])){
				isTransitive = 0;
				break;
			}

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(r[i][j] >= square[i][j]){
				isAntitransitive = 0;
				break;
			}

   if(isTransitive) 
	   return 0;
   else if(isAntitransitive)
	   return 1;
   else
	   return -1;
}

int isSymetric(const int r[size][size])
{
	int isSymetric = 1, isAntisymetric = 1; 

    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++)
            if(r[i][j] == r[j][i]){
				isAntisymetric = 0;
				break;
			}

    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++)
            if(r[i][j] != r[j][i]){
				isSymetric = 0;
				break;
			}

   if(isSymetric) 
	   return 1;
   else if(isAntisymetric)
	   return 0;
   else
	   return -1;
}

int isReflective(const int r[size][size])
{
    for(int i = 1; i < size; i++)
		if(r[0][0] != r[i][i])
			return -1;
    return r[0][0];
}

int main()
{
	int R[8][2] = {
		{1, 1},
		{1, 2},
		{1, 4},
		{2, 1},
		{2, 2},
		{3, 3},
		{4, 1},
		{4, 4}
	};
	int m[size][size] = {0};
	int q[size][size] = {0};

	MakeMatrix(m, R);
	PrintMatrix(m, size);

	int ref = isReflective(m);
	int sym = isSymetric(m);
	int trans = isTransitive(m);

	if (ref == -1)
		printf("Realation is neither reflective nor anti\n");
	else if (ref == 0)
		printf("Realation is antireflective\n");
	else
		printf("Realation is reflective\n");

	if (sym == -1)
		printf("Realation is neither symtric nor anti \n");
	else if (sym == 0)
		printf("Realation is antisymetric\n");
	else
		printf("Realation is symetric\n");

	if (trans == -1)
		printf("Realation is neither transitive nor anti \n");
	else if (trans == 0)
		printf("Realation is antitransitive\n");
	else
		printf("Realation is transitive\n");

	return 0;
}
