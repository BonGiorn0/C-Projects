#include <stdio.h>

enum{
	size = 10
};

int inCode(int code[], int x)
{
	for(int i = 0; i < size; i++)
		if (code[i] == x)
			return 1;
	return 0;
}

void BuildTree(int code[])
{
	for(int i = 0; i < size; i++)
		for(int j = 1; j < size + 3; j++){
			if(inCode(code, j))
				continue;
			printf("%d-%d ", code[i], j);
			code[i] = j;
			break;
		}

	int FirstLeft, SecondLeft;
	for(int i = 1; i < size + 3; i++)
		if(!inCode(code, i)){
			FirstLeft = i;
			break;
		}
	for(int i = 1; i < size + 3; i++){
		if(i == FirstLeft)
			continue;
		if(!inCode(code, i)){
			SecondLeft = i;
			break;
		}
	}
	printf("%d-%d", FirstLeft, SecondLeft);
}

int main()
{
	int code[size] = {4, 5, 6, 3, 2, 3, 4, 5, 5, 6};
	BuildTree(code);
	printf("\n");
	#if 1
	for(int i = 0; i < size; i++)
		printf("%d ", code[i]);
	printf("\n");
	#endif
	return 0;
}
