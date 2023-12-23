#include <stdio.h>
#include <math.h>
#include "functions.h"
#define LINE_LENGTH 40

double ValueFunction(double x){
    double y = cos(4 * x) * cos(4 * x);
    return y;
} 

int ChangeFunction(double x, double *y){
    *y = ValueFunction(x);
    if (*y < 0)
        return -1;
    if (*y > 0)
        return 1;
    return 0;
}
     
void DrawLine(char c, int n){
    for(int i = 0; i < n; i++)
        printf("%c", c);
    printf("\n");
}   
    
void TabulateFunction(int id, double a, double b, double h){
    DrawLine('=', LINE_LENGTH);
    printf("||      x       ||  (cos(4x))^2  ||   ||\n");
    DrawLine('=', LINE_LENGTH);
    if (!id){
        for(double x = a; x <= b; x += h)
            printf("||  %.7lf  ||  %.9lf  ||\n", x, ValueFunction(x));
        printf("||   %.7lf  ||  %.9lf  ||\n", b, ValueFunction(b));
    }else{
        double y;
        for(double x = a; x <= b; x += h){
            ChangeFunction(x, &y);
            printf("||  %.7lf  ||  %.9lf  || %d ||\n",
                            x, y, ChangeFunction(x, &y));
        }
        ChangeFunction(b, &y);
        printf("||   %.7lf  ||  %.9lf  || %d ||\n",
                        b, y, ChangeFunction(b, &y));
    }
    DrawLine('=', LINE_LENGTH);
}   

