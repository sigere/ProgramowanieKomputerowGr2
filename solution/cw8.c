#include <stdio.h>
#include <string.h>

long long int factorial(long long int n) {
	if (n == 1 || n == 0)
		return 1;
	return n * factorial(n - 1);
}

int fibbonacii(int n) {
	if (n < 1) return 0;
	if (n == 1) return 1;
	return fibbonacii(n - 1) + fibbonacii(n - 2);
}

void uno() {
	char a='a', b='b';
	char word[64];
	printf("podaj litere: \n");
	scanf_s("%c", &a);
	printf("podaj litere: \n");
	scanf_s("%c", &b);

	printf("podaj s³owa: \n");
	fgets(word, sizeof(word), stdin);

	for(int i=0; i<strlen(word); i++)
	{
		if (word[i] == a)
			word[i] = b;
		else if (word[i] == b)
			word[i] = a;
		i++;
	}

	printf("%s\n", word);
}
