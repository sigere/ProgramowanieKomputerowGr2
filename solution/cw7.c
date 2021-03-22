#include <stdio.h>

#define SWAP(x, y, T){ T SWAP = x; x = y; y = SWAP; }


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




void sztuczki_i_akrobacje(int* a, int* b, int n)
{//autorowi zadania raczej nie chodzilo o takie rozwiazanie :)
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				SWAP(b[j], b[j + 1], int);
				SWAP(a[j], a[j + 1], int);
			}
}

void insert_sort(int* arr, int n) //poprawiony
{
	int tmp;
	for (int i = 0; i < n-1; ++i)//dla i-tego (kazdego oprocz ostatniego) elementu
	{
		int tmp = i;
		for(int j = i+1; j<n; j++) //poszukaj 'za nim' elementu najmniejszego i przechowuj jego index w tmp
			if (arr[j] < arr[tmp])
				tmp = j;
		//znaleziony najmniejszy (mozliwe ze nie ma mniejszego, wtedy tmp == i)
		//zamien z i-tym
		SWAP(arr[i], arr[tmp], int);
	}
}