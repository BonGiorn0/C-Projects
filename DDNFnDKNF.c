#include <stdio.h>

struct bit{
	unsigned fourth	:1;
	unsigned third  :1;
	unsigned second	:1;
	unsigned first  :1;
};

union number{
	int decimal;
	struct bit bit;
};

void PrintRowAdd(union number n)
{
	char d1, d2, d3, d4;
	d1 = d2 = d3 = d4 = '!';
	if(n.bit.first)
		d1 = ' ';
	if(n.bit.second)
		d2 = ' ';
	if(n.bit.third)
		d3 = ' ';
	if(n.bit.fourth)
		d4 = ' ';
	printf("%cp ^ %cq ^ %cr ^ %cs V\n", d1, d2, d3, d4);
}

void PrintRowMult(union number n)
{
	char d1, d2, d3, d4;
	d1 = d2 = d3 = d4 = '!';
	if(!n.bit.first)
		d1 = ' ';
	if(!n.bit.second)
		d2 = ' ';
	if(!n.bit.third)
		d3 = ' ';
	if(!n.bit.fourth)
		d4 = ' ';
	printf("(%cp v %cq v %cr v %cs) ^\n", d1, d2, d3, d4);
}

int main()
{
	union number n;
	int ones[9] = {5, 7, 8, 9, 10, 11, 12, 14, 15};

	for(int i = 0; i < 9; i++){
		n.decimal = ones[i];
		PrintRowAdd(n);
	}

	printf("\n");

	int j = 0;
	for(int i = 0; i < 16; i++){
		if(i == ones[j]){
			j++;
			continue;
		}
		n.decimal = i;
		PrintRowMult(n);
	}
	return 0;
}
