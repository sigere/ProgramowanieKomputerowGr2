#include <stdio.h>
#include <math.h>
#include <string.h>

//Napisz funkcjê, która zwraca prawdê,
//jeœli liczba jest liczb¹ Armstronga


int czy_armstronga(int a)
{
	char tab[10];
	int lena, suma, b, c, pierwotna;
	suma = 0;
	sprintf_s(tab, sizeof(tab), "%d", a);
	lena = strlen(tab);
	pierwotna = a;
	for (int i = 0; i <= (lena - 1); ++i)
	{
		b = a % 10;
		c = b;
		for (int i = 0; i < (lena - 1); ++i)
		{
			c = c * b;
		}
		suma += c;
		a = a / 10;
	}
	return (pierwotna == suma);
}

void test_czy_armstronga()
{
	int a;
	printf("Podaj liczbe:");
	if (scanf_s("%d", &a) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane.\n");
		return;
	}
	printf("Liczba %d %s liczba Armstronga\n", a, czy_armstronga(a) ? "jest" : "nie jest");
}

//Napisz funkcjê, która zwraca prawdê, 
//je¿eli argumenty funkcji s¹ zaprzyjaŸnione.


int czy_zaprzyjaznione(int a, int b)
{
	int sumaa, sumab, i;
	sumaa = sumab = 0;
	char taba[10], tabb[10];
	sprintf_s(taba, sizeof(taba), "%d", a);
	sprintf_s(tabb, sizeof(tabb), "%d", b);
	for (i = 1; i <= (a / 2); ++i)
	{
		if (a % i == 0)
		{
			sumaa += i;
		}
	}
	for (i = 1; i <= (b / 2); ++i)
	{
		if (b % i == 0)
		{
			sumab += i;
		}
	}
	if (sumaa == b && sumab == a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void test_czy_zaprzyjaznione()
{
	int a, b;
	printf("Podaj liczby:");
	if (scanf_s("%d%d", &a, &b) < 2 || ferror(stdin))
	{
		printf("Niepoprawne dane.\n");
		return;
	}
	printf("Liczby %d oraz %d %s zaprzyjaznione\n", a, b, czy_zaprzyjaznione(a, b) ? "sa" : "nie sa");
}

//Napisz funkcjê, która zwraca prawdê, jeœli liczba 
// (argument funkcji) jest liczb¹ pierwsz¹.

int czy_pierwsza(int a)
{
	int i;
	for (i = 2; i <= (a / 2); ++i)
	{
		if (a % i == 0)
		{
			return 0;
		}

	}
	return 1;
}

void test_czy_pierwsza()
{
	int a;
	printf("Podaj liczbe:");
	if (scanf_s("%d", &a) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane.\n");
		return;
	}
	printf("Liczba %d %s pierwsza\n", a, czy_pierwsza(a) ? "jest" : "nie jest");
}