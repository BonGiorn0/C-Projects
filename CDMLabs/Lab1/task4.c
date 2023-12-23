#include <stdio.h>
#include <stdlib.h>

enum{
	UniversumSize = 10,
	ASize = 7,
	BSize = 6,
	CSize = 6,
};

int SolveEquasion(int id, int a[], int b[], int c[], int i){
	if (id == 1)
		return a[i] && !b[i] && !c[i];
	if (id == 2)
		return !((a[i] || b[i]) != c[i]);
	if (id == 3)
		return !(c[i] && !a[i]) && !(a[i] && !b[i]);
}

int CalculateArraySize(int id, int a[], int b[], int c[]){
	int XSize = 0;
	for(int i = 0; i < UniversumSize; ++i)
		XSize += SolveEquasion(id, a, b, c, i);
	return XSize;
}

void ConstructArray(int id, int X[],
					int a[], int b[], int c[], const int U[]){
	int j = 0;
	for(int i = 0; i < UniversumSize; ++i)
		if(SolveEquasion(id, a, b, c, i)){
			X[j] = U[i];
			j++;
		}
}

void ConstructBitSet(const int U[], const int X[], int XSize, int x[]){
	for(int i = 0; i < UniversumSize; ++i)
		for(int j = 0; j < XSize; ++j)
			if (U[i] == X[j]){
				x[i] = 1;
				break;
			}
}

void PrintArray(int X[], int l){
	printf("{");
	for(int i = 0; i < l - 1; ++i)
		printf("%d, ", X[i]);
	printf("%d}", X[l - 1]);
}

void PrintBoolean(int X[], int XSize){
	int *tmp;
	printf("\n{{},\n");
	tmp = malloc(sizeof(int));
	for(int i = 0; i < XSize; ++i){
		*tmp = X[i];
		PrintArray(tmp, 1);
		printf(", ");
	}
	printf("\n");
	tmp = malloc(2 * sizeof(int));
	for(int i = 0; i < XSize - 1; ++i){
		tmp[0] = X[i];
		for(int j = 1; j < XSize; ++j){
			if (i == j)
				continue;
			tmp[1] = X[j];
			PrintArray(tmp, 2);
			printf(", ");
		}
	}
	free(tmp);
	printf("\n");
	PrintArray(X, XSize);
	printf("}\n");
}

int main(){
	const int U[UniversumSize] = {1, 2, 3 , 4, 5, 6, 7, 8, 9, 10 },
		  				A[ASize] = {1, 2, 3, 4, 5, 6, 7},
						B[BSize] = {5, 6, 7, 8, 9, 10},
						C[CSize] = {1, 2, 3, 8, 9, 10};
	int a[UniversumSize] = {0},
		b[UniversumSize] = {0},
		c[UniversumSize] = {0};
	int S1Size, S2Size, S3Size;
	int *S1, *S2, *S3;

	ConstructBitSet(U, A, ASize, a);
	ConstructBitSet(U, B, BSize, b);
	ConstructBitSet(U, C, CSize, c);

	S1Size = CalculateArraySize(1, a, b, c);
	S2Size = CalculateArraySize(2, a, b, c);
	S3Size = CalculateArraySize(3, a, b, c);

	S1 = malloc(S1Size * sizeof(int));
	S2 = malloc(S2Size * sizeof(int));
	S3 = malloc(S3Size * sizeof(int));
	
	ConstructArray(1, S1, a, b, c, U);
	ConstructArray(2, S2, a, b, c, U);
	ConstructArray(3, S3, a, b, c, U);

	printf("First set: ");
	PrintArray(S1, S1Size);
	printf("\n");

	printf("Second set: ");
	PrintArray(S2, S2Size);
	printf("\n");

	printf("Third set: ");
	PrintArray(S3, S3Size);
	printf("\n");

	printf("Third set power: %d\n", S3Size);

	printf("Third set boolean: ");
	PrintBoolean(S3, S3Size);


	free(S1);
	free(S2);
	free(S3);

	return 0;
}
