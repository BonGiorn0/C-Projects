#include <stdio.h>
#include "graph.h"

enum{
	size = 3
};

int main()
{
	int R1[size][size] = {
		{1, 0, 1},
		{0, 1, 0},
		{0, 1, 1}
	};
	int R2[size][size] = {
		{1, 0, 1},
		{0, 0, 0},
		{1, 0, 1}
	};

	int U[size][size], X[size][size], SX[size][size],
		R1C[size][size], R2C[size][size],
		R1T[size][size], R2T[size][size],
		Comp1[size][size], Comp2[size][size];
	ConstructUnion(U, R1, R2, size);
	ConstructCrossing(X, R1, R2, size);
	ConstructSymetricalCrossing(SX, R1, R2, size);
	ConstructComplementary(R1C, R1, size);
	ConstructComplementary(R2C, R2, size);
	TranspondMatrix(R1T, R1, size);
	TranspondMatrix(R2T, R2, size);
	MultMatrix(Comp1, R1, R2, size);
	MultMatrix(Comp2, R2, R1, size);
	printf("R1 | R2:\n");
	PrintMatrix(U, size);
	printf("R1 & R2:\n");
	PrintMatrix(X, size);
	printf("R1 ^ R2:\n");
	PrintMatrix(SX, size);
	printf("!R1:\n");
	PrintMatrix(R1C, size);
	printf("!R2:\n");
	PrintMatrix(R2C, size);
	printf("R1 o R2:\n");
	PrintMatrix(Comp1, size);
	printf("R1 o R2:\n");
	PrintMatrix(Comp2, size);
	printf("R1^-1:\n");
	PrintMatrix(R1T, size);
	printf("R2^-1:\n");
	PrintMatrix(R2T, size);
	return 0;
}
