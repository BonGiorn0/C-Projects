#include <stdio.h>

void PrintReverse(int count)
{
    int k;
    printf("Enter a number or smth else to stop: ");

    if (!scanf("%d", &k))
        return;
    PrintReverse(++count);
    printf("#%d: %2d\n", count, k );
}

int main()
{
    PrintReverse(0);
    return 0;
}
