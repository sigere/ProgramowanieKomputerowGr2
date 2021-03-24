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
