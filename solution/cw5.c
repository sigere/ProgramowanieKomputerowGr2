#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


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