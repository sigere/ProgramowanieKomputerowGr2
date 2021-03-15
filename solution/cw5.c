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