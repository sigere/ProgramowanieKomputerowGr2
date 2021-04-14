#include <stdio.h>
#include <math.h>
#include <string.h>

#define FN(x) {if(x<=-1) printf("%f", x*x*cos(x)); else if(x<=1) printf("%f", x*x*x+2); else printf("%f", x*x*cos(x) + 2.5);}


int z2(double** arr, int n, int m, double a, double b, double* srednia) {
	*srednia = 0;
	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a <= arr[i][j] && arr[i][j] <= b) result++;
			*srednia += arr[i][j];
		}
	}
	*srednia /= (n * m);
	return result;
}
void test_z2() {
	int n = 10;
	int m = 10;
	double arr[10][10];
	double srednia;
	double a = 1.5, b = 5.5;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr[i][j] = rand();
}


int zadanie4k(char* buf, int b, int i)
{
	if (i >= b)
		return -1;

	if (buf[i] % 2 != 0)
		return buf[i];

	return zadanie4k(buf, b, i++);
}
void test_zadanie4k()
{
	int a, b;
	char buf[200];
	int i = 0;
	printf("Podaj liczbe calkowita dodatnia: \n");
	if (scanf_s("%d", &a) < 1 || ferror(stdin)) {
		printf("Niepoprawne dane \n");
		return;
	}
	sprintf_s(buf, sizeof(buf), "%d", a);
	b = strlen(buf);
	int tmp = zadanie4k(buf, b, i);
	if (tmp) printf("%c\n", tmp);
	else printf("dupa123, nie ma nieprzystych");
}