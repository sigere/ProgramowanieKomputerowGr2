#include <stdio.h>
#include <math.h>
#include <string.h>
#include "cw5.h"
#include "cw6.h"
#include "cw7.h"
#include "cw4.h"
#include "cw3.h"
#include <stdbool.h>

void bouble_matrix(int** arr, int n, int m) {
	printf("%d", arr[0][0]);
	for (int i = 0; i < n * m - 1; i++)
		for (int j = 0; j < n * m - i - 1; j++);
	//printf("%d", arr[0]);
	/*if (arr[j / m][j % m] > arr[j / m][(j + 1) % m])
		SWAP(arr[j / m][j % m], arr[j / m][(j + 1) % m], int);*/
}

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
	printf("%.12lf\n", pi(20));

	//printf("%f", monte_carlo(100000000));

	printf("%f\n", integral(100, 0, 1));

	int arr[] = { 1,3,2,4,5,2,1,3,2,8 };
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	bouble_sort(arr, n);
	for (int i = 0; i < n; ++i)
		printf("%d, ", arr[i]);
	printf("\n");


	int arr2[5][4] = {
			{0,2,1,7},
			{1,2,3},
			{0,8,1,8},
			{1,3,1,5},
			{1,3,8,2}
	};

	bouble_matrix(arr2, 5, 4);
	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
			printf("%d ", arr2[i][j]);
		printf("\n");
	}*/
	printf("\n");
}

