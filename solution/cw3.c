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
	lena = (int)strlen(tab);
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

int czy_parzysta(int a)
{
	return a % 2 == 0;
}

void test_czy_parzysta()
{
	int a;
	printf("Podaj a:");
	if (scanf_s("%d", &a) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane.\n");
		return;
	}
	printf("Liczba %d jest %s.\n", a, czy_parzysta(a) ? "parzysta" : "nieparzysta");
}

//SprawdŸ, czy liczba jest potêg¹ dwójki

void test_sprintf()
{
	int a;
	char buf[10];
	printf("Podaj a:");
	if (scanf_s("%d", &a) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane.\n");
		return;
	}
	sprintf_s(buf, sizeof(buf), "%d", a);
	printf("%s\n%c\n", buf, buf[0]);
}

int czy_potega_dwojki(int a)
{
	int b = a / 2;
	if (a == 1)
	{
		return 1;
	}
	if (a % 2 != 0)
	{
		return 0;
	}
	while (b > 1)
	{
		if (b % 2 == 1)
		{
			return 0;
		}
		b = b / 2;
	}
	return 1;
}

void test_potega_dwojki()
{
	int a;
	printf("Podaj liczbe:");
	if (scanf_s("%d", &a) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane.\n");
		return;
	}
	printf("Liczba %d %s potega dwojki.\n", a, czy_potega_dwojki(a) ? "jest" : "nie jest");
}

int czy_potega_dwojki_2(int a)
{
	int i;
	for (i = 1; i < a; i *= 2) {}
	return i == a;
}


//SprawdŸ, czy liczba jest automorficzna

int czy_automorficzna(int a)
{
	char buf[10], buf2[25];
	int lena, lena2;
	sprintf_s(buf, sizeof(buf), "%d", a);
	lena = (int)strlen(buf);
	sprintf_s(buf2, sizeof(buf2), "%d", a * a);
	lena2 = (int)strlen(buf2);
	for (int i = lena - 1, j = lena2 - 1; i >= 0; --i, --j)
	{
		if (buf[i] != buf2[j])
		{
			return 0;
		}
	}
	return 1;
}

void test_czy_automorficzna()
{
	int a;
	printf("Podaj liczbe:");
	if (scanf_s("%d", &a) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane\n");
		return;
	}
	printf("Liczba %d %s", a, czy_automorficzna(a) ? "jest automorficzna" : "nie jest automorficzna");
}
