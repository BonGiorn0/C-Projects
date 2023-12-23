#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main()
{
	stack *s;
	queue q;
	char str[50];
	StackInit(&s);
	StackPush(&s, "qwerty");
	printf("%s", StackTop(s));
	StackPop(&s, str);
	printf("%s", str);
	QueuePut(&q, "ytrewq");
	QueueGet(&q, str);
	printf("%s", str);
	return 0;
}
