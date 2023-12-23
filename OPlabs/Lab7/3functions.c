#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define LINE_LENGTH 35


void DrawLine(char c, int n){
    for(int i = 0; i < n; i++)
        printf("%c", c);
    printf("\n");
}

double f(double x){
    double y = cos(4 * x) * cos(4 * x);
    return y;
}

void WithFor(double a, double b, double h)
{
    for(double x = a; x <= b; x += h)
        printf("||  %.7lf  ||  %.9lf  ||\n", x, f(x));
}

void WithWhile(double a, double b, double h)
{
    double x = a;
    while (x <= b){
        printf("||  %.7lf  ||  %.9lf  ||\n", x, f(x));
        x += h;
    }
}
void WithDoWhile(double a, double b, double h)
{
    double x = a;
    do{
        printf("||  %.7lf  ||  %.9lf  ||\n", x, f(x));
        x += h;
    }while (x <= b);
}

void SelectFunction(void (**p)(double, double, double), int id)
{
    switch(id){
    case 1:
        *p = WithFor;
        break;
    case 2:
        *p = WithWhile;
        break;
    case 3:
        *p = WithDoWhile;
        break;
    }
}
void TabulateFunction(void (*func)(double, double, double),
                        double a, double b, double h){
    DrawLine('=', LINE_LENGTH);
    printf("||      x       ||  (cos(4x))^2  ||\n");
    DrawLine('=', LINE_LENGTH);
    func(a, b, h);
    printf("||   %.7lf  ||  %.9lf  ||\n", b, f(b));
    DrawLine('=', LINE_LENGTH);
}

int main(){
    double a = -M_PI_2, b = 0, h;
    int id;
    void (*func)(double, double, double);
    printf("Enter a step of tabulation(in radians): ");
    scanf("%lf", &h);
    printf("How do you want to tabulate a fuction?\n"
            "#1 with for loop\n"
            "#2 with while loop\n"
            "#3 with do while loop\n"
            "Enter the number oh your choice: ");
    scanf("%d", &id);
    SelectFunction(&func, id);
    TabulateFunction(func, a, b, h);
    return 0;
}
