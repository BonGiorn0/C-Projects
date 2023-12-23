#include <stdio.h>
#include <math.h>

void DrawLine(int n){
	for(int i = 0; i < n; i++)
		printf("-");
	printf("\n");

}

int main(){
	double a, b, step;
	double Accuracy;
	const int LineLength = 56;
	printf("Enter the limits of tabulation and its step: ");
	scanf("%lf %lf %lf", &a, &b, &step);
	printf("Enter the accuracy of Taylor series(0.01, 0.1E-5 etc.): ");
	scanf("%lf", &Accuracy);

	DrawLine(LineLength);
	printf("|     x      |       ln(x)        |   Taylor series    |\n");
	DrawLine(LineLength);
	for(double i = a; i <= b; i += step){
		double tln = 0;
		if (i <= 1){
			printf("|   %06.3f   |        X should be more then 1!         |\n", i);
			DrawLine(LineLength);
		}else{ 
			int j = 0;
			double elem;
			do{
				elem = (1.0 / (2 * j + 1)) * pow((i - 1) / (i + 1), 2 * j + 1);
				tln += elem;
				++j;
			}while(elem > Accuracy);
			tln *= 2;
			printf("|   %06.3f   | %0.16lf | %0.16lf |\n",
					i, log(i), tln);
		}
	}
	DrawLine(LineLength);
	
	return 0;
}
