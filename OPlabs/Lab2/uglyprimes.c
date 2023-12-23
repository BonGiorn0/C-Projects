#include <stdio.h>

int main(){
	int n;
	int DividerIsPrime = 1, nIsPrime = 1;
	printf("Enter the number: ");
	if(!scanf("%d", &n)){
		printf("Wrong input!\n");
		return 1;
	}

	printf("Prime dividers of your number are: ");
	for(int i = 2; i < n / 2 + 1; i++)
		if (n % i == 0){
			for (int j = 2; j < i / 2 + 1; j++)
				if (i % j == 0)
					DividerIsPrime = 0;
			if (DividerIsPrime)
				printf("%d ", i);
			DividerIsPrime = 1;
			nIsPrime = 0;
		}

	if (nIsPrime)
		printf("%d", n);

	printf("\n");
	return 0;
}
