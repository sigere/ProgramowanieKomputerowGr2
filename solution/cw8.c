#include <stdio.h>
#include <string.h>

long long int factorial(long long int n) {
	if (n == 1 || n == 0)
		return 1;
	return n * factorial(n - 1);
}

int fibbonacii(int n) {
	if (n < 1) return 0;
	if (n == 1) return 1;
	return fibbonacii(n - 1) + fibbonacii(n - 2);
}

float bisection(float(*function)(float),float precision, int a, int b)
{
	if (a > b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	if ((*function)(a) * (*function)(b) > 0)
		return -1.0;
	float val = (*function)((b + a) / 2);
	printf("val: %f\n", val);
	if (abs(val) < precision) {
		printf("%d, %d\n", a, b);
		return (b + a) / 2.0;
	}
	return val ? bisection(function,precision, (b + a) / 2, b) : bisection(function, precision, a, (b + a) / 2);
}

char* to_binary(int dec)
{
	if (dec == 0)
		return malloc(255 * sizeof(char));
	char digit = dec % 2 + '0';
	dec /= 2;
	return strcat(to_binary(dec),&digit);
}

int first_capital(char* text, int size, int n)
{
	if (n >= size)
		return -1;
	if ('A' <= text[n] && text[n] <= 'Z')
		return n;
	return first_capital(text, size, n+1);
}

int w_len(char* c)
{
	if (*c == '\0')
		return 0;
	else
		return w_len(c + 1) + 1;
}

void hanoi(int n, char x, char y, char z, FILE* fp)
{
	if (n == 1)
	{
		fprintf(fp, "przenies krazek 1 z %c na %c\n", x, y);
		printf("przenies krazek 1 z %c na %c\n", x, y);
		return;
	}
	hanoi(n - 1, x, z, y,fp);
	fprintf(fp, "przenies krazek %d z %c na %c\n",n, x, y);
	printf("przenies krazek %d z %c na %c\n",n, x, y);
	hanoi(n - 1, z, y, x,fp);
}
