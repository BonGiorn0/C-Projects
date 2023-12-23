#include <stdio.h>

int main(){
	const int Shift = 2;
	int matrix[128][128];
	int n, m;

	printf("Enter height and width of your matrix: ");
	scanf("%d %d", &n, &m);
	if (n == 0 || m == 0){
		printf("Height or width should be at least 1!\n");
		return 1;
	}

	for(int i = 0; i < n; ++i){
		printf("Enter the row #%d: ", i + 1);
		for(int j = 0; j < m; ++j){
			scanf("%d", *(matrix + i) + j);
		}
	}

	printf("Result of 2-up cyclic shift: ");

	if (n == 1){
		for(int i = 0; i < m; ++i)
			printf("%d ", matrix[i][0]);
		printf("\n");
		return 0;
	}

	int res[n][m];

	for(int i = Shift; i < n; ++i){
		for(int j = 0; j < m; ++j)
			res[i - Shift][j] = matrix[i][j];
	}
	for(int i = 0; i < Shift; ++i){
		for(int j = 0; j < m; ++j)
			*(*(res + i + n - Shift) + j) = *(*(matrix + i) + j);
	}

	for(int i = 0; i < n; ++i){
		printf("\n");
		for(int j = 0; j < m; ++j)
			printf("%d ", res[i][j]);
	}
	printf("\n");
	return 0;
}
