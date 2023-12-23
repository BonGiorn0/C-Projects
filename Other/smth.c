#include <stdio.h>
#include <stdarg.h>

int CountEvenNumbers(int n, ...)
{
	va_list vl;
	int res = 0, num;

	va_start(vl, n);
	for(int i = 0; i < n; ++i){
		num = va_arg(vl, int);
		if (!(num % 2))
			res++;
	}
	va_end(vl);
	return res;
}

int main()
{
	int res;
	res = CountEvenNumbers(3, 1, 2, 3);
	printf("%d\n", res);
	res = CountEvenNumbers(5, 10, 2, 4, 6, 8);
	printf("%d\n", res);
	return 0;
}
