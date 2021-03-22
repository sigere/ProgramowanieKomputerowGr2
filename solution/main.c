#include <stdio.h>
#include <math.h>
#include <string.h>
#include "cw5.h"
#include "cw6.h"
#include "cw7.h"
#include "cw4.h"
#include "cw3.h"
#include <stdbool.h>
#include <stdlib.h>

int main()
{
	/*printf("%s\n", checkIfPalindrome(101) ? "true" : "false");
	printf("%s\n", checkIfPalindrome(1101) ? "true" : "false");
	printf("%s\n", checkIfPalindrome(1223221) ? "true" : "false");
	printf("%s\n", checkIfPalindrome(1) ? "true" : "false");
	printf("%s\n", checkIfPalindrome(111) ? "true" : "false");

	printf("%d\n", reverseAndAdd(195));
	char string1[] = "ala Algieria alabama niea Ataman";
	startedWith('a', string1);
	char string2[] = "abcdefghijklmnopqrstuvwxyz";
	cipher(string2);
	char string3[] = "abc abcd abcde abc";
	printf("%d\n", longWordsCount(4, string3));

	printf("%f\n", bisection(0.0001, -2, 2));*/
	//printf("%.12lf\n", pi(20));

	//printf("%f", monte_carlo(100000000));

	//printf("%f\n", integral(100, 0, 1));

	/*int arr[] = { 1,3,2,4,5,2,1,3,2,8 };
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	bouble_sort(arr, n);
	for (int i = 0; i < n; ++i)
		printf("%d, ", arr[i]);
	printf("\n");*/

	time_t tt;
	int salt = time(&tt);
	srand(salt);
	int r = 5, c = 7;
	int** arr2 = (int*)malloc(r * sizeof(int*));
	for (int i = 0; i < r; ++i)
	{
		arr2[i] = malloc(c * sizeof(int));
		for (int j = 0; j < c; ++j)
			arr2[i][j] = rand()%10;
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			printf("%d ", arr2[i][j]);
		printf("\n");
	}
	printf("\n");


	bouble_matrix(arr2, r, c);
	
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			printf("%d ", arr2[i][j]);
		printf("\n");
	}

	printf("\n");
}

