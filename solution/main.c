#include <stdio.h>
#include <math.h>
#include <string.h>
#include "cw5.h"
#include "cw6.h"
#include "cw7.h"
#include "cw4.h"
#include "cw3.h"
#include "cw9.h"
#include "cw10.h"
#include "cw11.h"
#include <stdbool.h>
#include <stdlib.h>



int main()
{
	fToBinary();
	return 0;

	char* x = toDecimal("001100010011001000110011", 3 * 8);
	printf("%s\n", x);
	//toDecimal("001100010011001000110011", 3*8);

	//for (int i = 0; i < 3 * 8; i++)
	//	printf("%c", arr[i]);
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

	/*time_t tt;
	unsigned int salt = time(&tt);
	srand(salt);
	int r = 5, c = 7;
	int** arr2 = (int**)malloc(r * sizeof(int*));
	for (int i = 0; i < r; ++i)
	{
		arr2[i] = (int*)malloc(c * sizeof(int));
		for (int j = 0; j < c; ++j)
			arr2[i][j] = (int)rand()%10;
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

	printf("\n");*/

	/*printf("sztuczki i akrobacje\n");
	int b[] = { 9,8,7,6,5 };
	int a[] = { 4,3,1,2,0 };
	sztuczki_i_akrobacje(a, b, 5);
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < n; ++i)
		printf("%d, ", b[i]);
	printf("\n");*/
	/*int arr[] = { 1,3,2,4,5,2,1,3,2,8 };
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	insert_sort(arr, n);
	for (int i = 0; i < n; ++i)
		printf("%d, ", arr[i]);
	printf("\n");*/

	/*int arr[] = { 1,3,2,4,5,2,1,3,2,8 };
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; ++i)
		printf("%d, ", arr[i]);
	printf("\n");

	fragmentation(arr,10);
	FILE* fp;
	fopen_s(&fp, "hanoiKrzysztofMarczak.txt", "w+");
	hanoi(3,'a','b','c',fp);
	fclose(fp);*/

	//test();
	//float x = -1.1;
	//FN(x);

	return 0;
}

