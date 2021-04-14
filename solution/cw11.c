#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


struct node {
    int value;
} node;

struct ndge {
    struct node* from;
    struct node* to;
} edge;


char* toBinary(char* arr, int n)
{
    char* result = malloc(sizeof(char) * n * 8 + 1);
    result[n * 8] = NULL;
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = (int)arr[i];
        for (int c = 7; c >= 0; c--)
        {
            int tmp = x >> c;
            if (tmp & 1)
                result[j++] = '1';
            else
                result[j++] = '0';
        }
    }
    return result;
    /*for (int i = 0; i < n * 8; i++)
        printf("%d", result[i]);
    printf("\n");*/
}

void toDecimal(char* arr, int n)
{
    if (n % 8 || !n) {
        printf("Niepoprawne dane.");
        return;
    }

    char* result = (char*)malloc(sizeof(char) * n / 8 + 1);
    result[n / 8] = NULL;
    int k = 0;

    for (int i = 0; i < n / 8; ++i)
    {
        int letter = 0;
        for (int j = 0; j < 8; j++)
            letter += (arr[i * 8 + j] - '0') << (7-j);
        result[k++] = (char)(letter + '0');
    }
    return result;
}

void fToBinary()
{
    FILE* in;
    FILE* out;
    int c;
    int tmp = 0;
    fopen_s(&in, "input.txt", "r");
    fopen_s(&out, "output.txt", "w");
    if (in && out) 
        while ((c = getc(in)) != EOF)
        {
            char tmp[1];
            tmp[0] = (char)c;
            fprintf(out, "%s", toBinary(tmp,1));
        }
            
    else if (!in)
        perror("input.txt");
    else if (!out)
        perror("output.txt");

    if (in) fclose(in);
    if (out) fclose(out);
}