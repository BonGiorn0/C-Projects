#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#define DELIM "/.,;:?<>!@#$%^&*()-+=\" \n"

void PrintWords(char *str, ...)
{
    va_list vl;
    char *p;

    va_start(vl, str);
    for(p = str; p; p = va_arg(vl, char *)){
        char tmp[100];
        strcpy(tmp, p);
        char *token = strtok(tmp, DELIM);  
        while (token != NULL){
            printf("\"%s\" ", token);
            token = strtok(NULL, DELIM);
        }
        printf("\n");
    }
    va_end(vl);
}

int main()
{
    char s1[] = "Hello world!!!",
            s2[] = "Don't; do not: win-win ",
            s3[] = "asda@#Y%&^#*HG@G$@*#$Y";

    PrintWords(s1, NULL);
    printf("================================\n");
    PrintWords(s1, s2, NULL);
    printf("================================\n");
    PrintWords(s1, s2, s3, NULL);
    printf("================================\n");

    return 0;
}
