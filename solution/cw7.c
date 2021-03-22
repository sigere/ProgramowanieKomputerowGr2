#include <stdio.h>

#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

void bouble_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				SWAP(arr[j], arr[j + 1], int);
}

