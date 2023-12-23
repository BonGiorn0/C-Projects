#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	float *arr = malloc(n * sizeof(float));
	printf("%p\n", arr);

	for(int i = 0; i < n; i++)
		scanf("%f", &arr[i]);

	for(int i = 0; i < n; i++)
		printf("%.3f ", arr[i]);
	printf("\n");

	for(int i = n - 1; i >= 0; i--)
		printf("%.3f ", arr[i]);
	printf("\n");

	free(arr);
	printf("%f\n", arr[0]);

	return 0;
}
