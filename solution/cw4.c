#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

//SprawdŸ, czy liczba jest doskona³a

int czy_doskonala(int a)
{
	int b = 2, suma = 1;
	while (b <= (a / 2))
	{
		if (a % b == 0)
			suma = suma + b;
		++b;
	}
	return suma == a;
}

void czy_doskonala_test()
{
	int a;
	printf("Podaj liczbe:");
	if (scanf_s("%d", &a) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane.\n");
		return;
	}
	printf("Liczba %d %s doskonala.\n", a, czy_doskonala(a) ? "jest" : "nie jest");
}

void czy_n_doskonale()
{
	int n, i, a = 0, suma = 0, ilosc = 0;
	double srednia = 0;
	char buf[100] = "";
	printf("Podaj, ile liczb chcesz sprawdziæ:\n");
	if (scanf_s("%d", &n) < 1 || ferror(stdin) || n <= 0)
	{
		printf("Niepoprawne dane.\n");
		return;
	}
	printf("Wymagane jest podawanie liczb po kolei.\n");
	for (i = 0; i < n; ++i)
	{
		int a;
		printf("Podaj liczbe: \n");
		if (scanf_s("%d", &a) < 1 || ferror(stdin))
		{
			printf("Niepoprawne dane.\n");
			--i;
			continue;
		}
		if (czy_doskonala(a))
		{
			suma += a;
			ilosc += 1;
		}
	}
	if (ilosc == 0)
	{
		printf("W podanych liczbach nie ma liczb doskonalych");
	}
	else
	{
		srednia = suma / ilosc;
		printf("W podanych liczbach jest %d liczb doskonalych. Ich suma wynosi %d, a srednia %lf.\n", ilosc, suma, srednia);
	}
}

//Napisz funkcjê, która bêdzie wczytywa³a pojedyncze znaki 
//i wypisywa³a tylko te, które s¹ cyframi. 
//Aby zakoñczyæ wczytywanie nale¿y wpisaæ ENTER. 

void wypisz_liczby()
{
	int dlugosc;
	char znak[100] = "";
	printf("Podaj znaki:");
	scanf_s("%s", znak, sizeof(znak));
	dlugosc = strlen(znak);
	for (int i = 0; i <= dlugosc; ++i)
	{
		if (isdigit(znak[i]))
		{
			printf("%c", znak[i]);
		}
	}
}

void print_digits()
{
	int i;
	while (true)
	{
		i = getchar();
		if (i == 10)
			return;
		while (i != 10)
		{
			if (i >= '0' && i <= '9')
				printf("%c", (char)i);
			i = getchar();
		}
	}
}

void wypisz_liczby2()
{
	printf("Podaj znaki: \n");
	int a = getchar();
	printf("Wpisa³es: ");
	putchar(a);
}

//Napisz program do wypisywania wyrazów n-elementowego ci¹gu
//którego pierwszy element p(a(1) = p), a wartoœæ kolejnych elementów
//okreœla wzór.

void ciagn()
{
	int c, p, n;
	printf("Podaj pierwszy wyraz, dlugosc ciagu i wartosc dodawana:");
	if (scanf_s("%d%d%d", &p, &n, &c) < 3 || ferror(stdin))
	{
		printf("Niepoprawne dane\n");
		return;
	}
	int a = p;
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", a);
		a = a * 2 + c;
	}
}

//Napisz funkcjê, która wypisuje n kolejnych wyrazów ci¹gu Fibonacciego.

void fibonacci()
{
	int n, a = 0, b = 1, c;
	printf("Podaj n:\n");
	if (scanf_s("%d", &n) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", b);
		c = b;
		b = a + b;
		a = c;
	}
}

//Napisz funkcjê maks, która zwraca najwiêksz¹ liczbê naturaln¹
//z zadanego przedia³u, która spe³nia nierównoœæ

void maks_n()
{
	int a, b;
	printf("Podaj pierwsza i ostatnia liczbe przedzialu: \n");
	if (scanf_s("%d%d", &a, &b) < 2 || ferror(stdin))
	{
		printf("Niepoprawne dane\n");
		return;
	}
	for (int i = b; i >= a; --i)
	{
		if ((i * i * i + 20 * i) < (33 * i * i + 370))
		{
			printf("Najwieksza liczba to: %d\n", i);
			return;
		}
	}
	printf("Nie ma takiej liczby");
}

//ZnajdŸ najmniejsze n spe³niaj¹ce nierównoœæ

void najwiekszen()
{
	double b = 1.02, n = 1.0;
	double a = 0;
	while (a != 1)
	{
		if (b > 1000 * n * n)
		{
			a = 1;
		}
		else
		{
			n += 1;
			b = b * b;
		}
	}
	printf("Najmniejsze n, które spe³nia t¹ zale¿noœæ to %2lf.\n", n);
}

void najwiekszen2()
{
	double n = 1;
	while (pow(1.02, n) <= 1000 * n * n)
	{
		n += 1;
	}
	printf("Najwieksza liczba to %lf\n", n);
}

//Napisz funckjê, która wyznacza najwiêkszy wspólny dzielnik.

void nwd()
{
	int a, b;
	printf("Podaj dwie liczby: \n");
	if (scanf_s("%d%d", &a, &b) < 2 || ferror(stdin))
	{
		printf("Niepoprawne dane\n");
		return;
	}
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	printf("Najwiekszy wspolny dzielnik to %d\n", a);
}

//Napisz funkcjê, która zamienia liczby na system u2.

void repair(int* tab)
{
	int tmp = 0;
	for (int i = sizeof(int) * 8 - 1; i > 0; i--)
	{
		tab[i] += tmp;
		tmp = tab[i] / 2;
		tab[i] %= 2;
	}
	if (tmp) printf("Overflow!");
}

void dec2u2()
{
	int a;
	printf("Podaj a:\n");
	if (scanf_s("%d", &a) < 1 || ferror(stdin))
	{
		printf("Niepoprawne dane\n");
		return;
	}
	bool negative = false;
	if (a < 0)
		negative = true;
	a = abs(a);
	int tab[sizeof(int) * 8];
	int i = sizeof(int) * 8 - 1;
	while (i >= 0)
	{
		tab[i--] = a % 2;
		a /= 2;
	}
	if (negative)
	{
		for (i = sizeof(int) * 8 - 1; i >= 0; i--)
		{
			if (tab[i] == 0)
				tab[i] = 1;
			else
				tab[i] = 0;
		}
		tab[sizeof(int) * 8 - 1]++;
		repair(tab);
	}

	for (int j = 0; j < sizeof(int) * 8; j++)
		printf("%d", tab[j]);
	printf("\n");
}
