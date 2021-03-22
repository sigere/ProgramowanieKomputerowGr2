#include <stdio.h>

#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

void bouble_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				SWAP(arr[j], arr[j + 1], int);
}

void bouble_matrix(int** arr, int n, int m) {
	for (int i = 0; i < n * m - 1; i++)
		for (int j = 0; j < n * m - i - 1; j++)
			if (arr[j / m][j % m] > arr[(j+1) / m][(j + 1) % m])
				SWAP(arr[j / m][j % m], arr[(j+1) / m][(j + 1) % m], int);
}