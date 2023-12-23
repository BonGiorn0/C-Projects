#include <stdio.h>
#include <stdarg.h>

int LastDigit(int n)
{
	return n % 10;
}

int MyExcellentFunction(int n, ...)
{
	va_list vl;
	int res = 0;

	va_start(vl, n);
	for(int i = 0; i < n; ++i){
		double num = (va_arg(vl, double));
		if (LastDigit((int)num) == LastDigit((int)(num * 10)))
				res++;
	}
	va_end(vl);
	return res;
}

int main()
{
	int res;
	res = MyExcellentFunction(3, 25.52, 69.99, 34.56);
	printf("%d\n", res);
	res = MyExcellentFunction(4, 25.52, 69.99, 34.56, 44.44);
	printf("%d\n", res);
}
