#include <stdio.h>

/*float SolveEquasion(float x, float n ){
	if (n == 7){
		return n;
	}else{
		return n - (x * x) / SolveEquasion(x, n + 2);
	}
}*/

int main(){
	float Ti, x;
	printf("Enter the X: ");
	scanf("%f", &x);
	Ti = x / (1 - x*x /(3 - x*x / (5 - x*x / 7)));
	printf("Result is %f \n", Ti);
	return 0;
}
