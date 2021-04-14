#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void toBinary(char* arr, int n)
{
    char* result = malloc(sizeof(char)*n*8);
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = (int)arr[i];
        for (int c = 7; c >= 0; c--)
        {
            int tmp = x >> c;
            if (tmp & 1)
                result[j++] = 1;
            else
                result[j++] = 0;
        }
    }
    for (int i = 0; i < n * 8; i++)
        printf("%d", result[i]);
    printf("\n");
}

void toDecimal(char* arr, int n)
{
    if (n % 8 || !n) {
        printf("Niepoprawne dane.");
        return;
    }

    for (int i = 0; i < n / 8; ++i)
    {
        int letter = 0;
        for (int j = 0; j < 8; j++)
            letter += (arr[i * 8 + j] - '0') << (7-j);
        printf("%c", letter+'0');
    }
    printf("\n");
}