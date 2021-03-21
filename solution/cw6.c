#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float function(float input) {
	return input * input * input - input + 1;
}

float bisection(float precision, int a, int b)
{
	if (a > b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	if (function(a) * function(b) > 0)
		return -1.0;
	float val = function((b + a) / 2);
	printf("val: %f\n", val);
	if (abs(val) < precision) {
		printf("%d, %d\n", a, b);
		return (b + a) / 2.0;
	}
	return val ? bisection(precision, (b + a) / 2, b) : bisection(precision, a, (b + a) / 2);
}


double pi(int n)
{
	double x = sqrt(2.0);
	double result = 1.0;
	for (int i = 1; i < n; ++i)
	{
		result *= x / 2.0;
		x = sqrt(x + 2);
	}
	return 2.0 / result;
}

double monte_carlo(int n)
{
	time_t tt;
	int salt = time(&tt);
	srand(salt);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		double x = rand() / (double)RAND_MAX;
		double y = rand() / (double)RAND_MAX;
		double tmp = x * x + y * y;
		if (tmp <= 1)
			m++;
	}
	return 4.0 * (double)m / (double)n;
}