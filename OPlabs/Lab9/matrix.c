#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintMatrix(int **m, int n)
{
	for(int i = 0; i < n; i++){
		if(i != 0)
			printf("\n");
		for(int j = 0; j < n; j++)
			printf("%d ", m[i][j]);
	}
}

void ReadMatrix(int **m, int n)
{
	char row[100] = "";

	for(int i = 0; i < n; i++){
		int j = 0;
		fgets(row, 100, stdin);
		char *token = strtok(row, " \n");
		while(token){
			m[i][j] = atoi(token);
			j++;
			token = strtok(NULL, " \n");
		}
		if(j != n){
			printf("There should be %d elements in a row!\n", n);
			exit(1);
		}
	}
}

void CalculateThing(int **m, int size, int *col, int *sum)
{
	int MinSum = (unsigned)(-1) / 2;
	int MinCol = 0;
	for(int i = 0; i < size - 1; i++){
		int s = 0;
		for(int j = i + 1; j < size; j++){
			s += m[j][i];
			m[j][i] = 0;
		}
		if (s < MinSum){
			MinSum = s;
			MinCol = i;
		}
	}
	*col = MinCol;
	*sum = MinSum;
}

int main()
{
	int n, col = 0, sum = 0;
	printf("Enter a size of your square matrix: ");
	scanf("%d", &n);

	if (n < 1){
		printf("There shoud be at least 1 row!\n");
		return 0;
	}

	getchar();
	int **matrix = malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++)
		matrix[i] = malloc(n *  sizeof(int));

	printf("Enter your matrix row by row:\n");
	ReadMatrix(matrix, n);
	CalculateThing(matrix, n, &col, &sum);

	if(n < 2){
		printf("There's no elements under diagonal\n");
		return 0;
	}

	printf("\n");
	PrintMatrix(matrix, n);
	printf("\n");
	printf("Smallest sum in column %d: %d\n", col + 1, sum);

	return 0;
}
