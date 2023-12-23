#include <stdio.h>

int DividerIsPrime(int x){
	for (int j = 2; j < x / 2 + 1; j++)
		if (x % j == 0)
			return 0;
	return 1;
}

int main(){
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);

	printf("Prime dividers of your number are: ");
	for(int i = 1; i < n / 2 + 1; i++)
		if (n % i == 0){
			if (DividerIsPrime(i))
				printf("%d ", i);
		}

	if (DividerIsPrime(n))
		printf("%d", n);

	printf("\n");
	return 0;
}
