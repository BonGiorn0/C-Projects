#include <stdio.h>

enum{
	a = 152, b = 13, c = 77, d = 123,
	e = 8, f = 10, g = 50
};

int main(){
	int x, text, graphics, symbols;
	x = a - (b + c + d - (e + f + g));

	if (x < 0){
		printf("Such system doesn\'t exist\n");
		return 0;
	}

	text = b - (e + f - x);
	graphics = c - (e + g - x);
	symbols = d - (f + g - x);

	printf("Only text: %d \n", text);
	printf("Only graphics: %d \n", graphics);
	printf("Only symbols: %d \n", symbols);

	return 0;
}
