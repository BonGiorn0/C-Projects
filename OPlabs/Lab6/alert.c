#include <stdio.h>

int main()
{
    printf("Error in file \"%s\" at line %d\n", __FILE__, __LINE__);
    return 0;
}
