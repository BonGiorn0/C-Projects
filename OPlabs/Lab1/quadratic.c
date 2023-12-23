#include <stdio.h>
#include <math.h>

/*float discriminant(float a, float b, float c){
	return b * b - 4 * a * c;
}*/

int main(){
	float a, b, c, D, x1, x2, n;
	static int ArgsAmount = 3;
	printf("Enter coefitiens of your quadratic equasion : ");
	n = scanf("%f %f %f", &a, &b, &c);
	if (n != ArgsAmount){
		printf("Wrong input!\n");
		return 1;
	}
	if (a == 0){
		printf("Equasion isn\'t quadratic!\n");
		return 2;
	}
	D = b * b - 4 * a * c;
	if (D < 0){
		printf("No real solutions.\n");
		return 0;
	}
	x1 = (-b - sqrt(D)) / (2 * a);
	x2 = (-b + sqrt(D)) / (2 * a);
	printf("The roots are %f and %f \n",x1,x2);
	return 0;

}
