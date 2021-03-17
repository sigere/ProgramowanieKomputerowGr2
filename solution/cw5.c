#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


bool checkIfPalindrome(int a)
{
	char text[100];
	int index = sprintf_s(text, 100, "%d", a);
	char* copy = _strrev(_strdup(text));
	for (int i = 0; i < index; i++)
		if (copy[i] != text[i])
			return false;
	return true;
}

int reverseAndAdd(int a)
{
	while (!checkIfPalindrome(a))
	{
		char text[100];
		int index = sprintf_s(text, 100, "%d", a);
		int b = 0;
		for (int i = 0, pos = 1; i < index; i++, pos *= 10)
			b += (text[i] - '0') * pos;
		a += b;
	}
	return a;
}

void startedWith(char c, char* str)
{
	char* tmp = NULL; //pomocnicza zmienna wymagana przez strtok_s
	char* token = strtok_s(str, " ,\t\n", &tmp);
	while (token)
	{
		if ((char)tolower(token[0]) == c)
			printf("%s ", token);
		token = strtok_s(NULL, " ,\t\n", &tmp);
	}
	printf("\n");
}

void cipher(char* text)
{
	char tmp[100]; //pomocnicza zmienna, do wygenerowania klucza
	int key[100]; // klucz sk³adaj¹cy siê z kolejno: ostatniej, pierwszej, drugiej.. n-1-tej
				  // litery szyfrowanego tekstu (finalnie o takiej samej d³ugoœci co text)
	int index = sprintf_s(tmp, 100, "%c%s", text[strlen(text) - 1], text) - 1; // d³ugoœæ textu
	for (int i = 0; i < index; i++)
		key[i] = toupper(tmp[i]) - 'A';

	for (int i = 0; i < index; i++) // przestawienie 
		text[i] = (((toupper(text[i]) - 'A' + key[i])) % ('Z' - 'A')) + 'A';

	printf("%s\n", text);
}

int longWordsCount(int n, char* str) {	
	char* tmp = NULL; //pomocnicza zmienna wymagana przez strtok_s
	char* token = strtok_s(str, " ,\t\n", &tmp);
	
	int result = 0;
	while (token)
	{
		if (strlen(token) >= n)
			result++;
		token = strtok_s(NULL, " ,\t\n", &tmp);
	}
	return result;
}