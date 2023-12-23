#include <stdio.h>

int P(char x, char c){
	if (x == 'a' && c == 'a')
		return 0;
	if (x == 'a' && c == 'b')
		return 1;
	if (x == 'b' && c == 'a')
		return 0;
	if (x == 'b' && c == 'b')
		return 1;
	return 0;
}

int main(){
	int res = 1;
	for(int x = 'a'; x <= 'b'; ++x)
		res = res && P(x, 'b');
	printf("For all x is P(x, b).\n");
	if (res){
		printf("Statement is true\n");
	}else{
		printf("Statement is false\n");
	}

	return 0;
}
