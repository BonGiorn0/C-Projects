#include <stdio.h>
#include <math.h>
#include "functions.h"
#define _USE_MATH_DEFINES

int main(){
    double a = -M_PI_2, b = 0, h;
    printf("Enter a step of tabulation(in radians): ");
    scanf("%lf", &h);
    TabulateFunction(0, a, b, h);
    return 0;
}
