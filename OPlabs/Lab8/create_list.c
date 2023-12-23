#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int RandValue(int low, int top)
{
	return (rand() % (top - low + 1) + low);
}

void RandDate(FILE *f)
{
	int day = RandValue(1, 28);
	int month = RandValue(1, 12);
	int year = RandValue(2004, 2005);
	fprintf(f, "%02d.%02d.%04d", day, month, year);
}

int main()
{
	char str[100];
	FILE *f, *list;
	f = fopen("in.txt", "r");
	list = fopen("list.txt", "w");
	for(int i = 0; i < 27; ++i){
		fgets(str, 100, f);
		str[strlen(str) - 1] = '\0';
		int OP = RandValue(2, 5);
		int CDM = RandValue(2, 5);
		int Calc = RandValue(2, 5);
		int Algebra = RandValue(2, 5);
		int History = RandValue(2, 5);
		fprintf(list, "%s ", str);
		RandDate(list);
		fprintf(list, " %d %d %d %d %d\n", OP, CDM, Calc, Algebra, History);
	}
	fclose(f);
	fclose(list);
	return 0;
}
