#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int** fragmentation(int* arr, int n)
{
	int k = n % (int)sqrt(n) ? (int)sqrt(n) + 1 : (int)sqrt(n);// jesli elementów jest wiecej niz (int)n/k, zwiekszam k o jeden na pozosta³e elementy
	int elements = n;

	int* used = malloc(n * sizeof(int));//pomocnicza tablica - przechowuje informacje, których elementow z arr ju¿ u¿yto
	for (int i = 0; i < n-1; i++)
		used[i] = 0;

	int index_of_biggest = 0;// znajdz najwiekszy element
	for (int i = 0; i < n; i++)
		if (arr[i] > arr[index_of_biggest])
			index_of_biggest = i;
	
	int** result = (int**)malloc(k * sizeof(int*));//tablica dwówymiarowa - deklaracja wierszy
	for (int i = 0; i < k; i++) {
		int size = n / (int)sqrt(n);// rozmiar wiersza (liczba komorek)
		result[i] = (int*)malloc(size * sizeof(int)); //deklaracja komorek w wierszach
		for (int j = 0; j < size && elements--; j++) //elements to liczba pozosta³ych w arr nieu¿ytych wartoœci,
		{											// gdy siê wyzeruje, nie mo¿na kontynuowaæ
			int index = index_of_biggest; // znajdz najmniejszy(jego index) z nieu¿ytych
			for (int q = 0; q < n; q++)
				if (arr[q] < arr[index] && !used[q])
					index = q;
			used[index] = 1;//zaznacz, ¿e u¿y³eœ tej wartoœci
			result[i][j] = index; //zapisz ten index
		}
	}


	//-------wyswietlanie----------
	elements = n;
	int size = n / (int)sqrt(n);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < size && elements--; j++)
			printf("%d, ", arr[result[i][j]]);
		printf("\n");
	}


	return result;
}