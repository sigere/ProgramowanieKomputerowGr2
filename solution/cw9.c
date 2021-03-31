#include <stdio.h>

void print_file()
{
    FILE* f;
    fopen_s(&f,"input.txt", "r");
    int c;

    if (f) {
        while ((c = getc(f)) != EOF)
            putchar(c);
        fclose(f);
    }
    else
        perror("input.txt");
 }

void count_file()
{
    FILE* f;
    int c;
    int letters = 0;
    int words = 1;
    fopen_s(&f, "input.txt", "r");
    if (f) {
        while ((c = getc(f)) != EOF) {
            if (c == ' ') words++;
            letters++;
        }
        fclose(f);
        if (!letters) words = 0;
        printf("Liczba slow: %d\nLiczba liter: %d\n", words, letters);
    }
    else
        perror("input.txt");
}

void delete_empty_lines_from_file()
{
    FILE* in;
    FILE* out;
    int c;
    int tmp = 0;
    fopen_s(&in, "input.txt", "r");
    fopen_s(&out, "output.txt", "w");
    if (in && out) {
        while ((c = getc(in)) != EOF)
        {
            if (c != '\n' || tmp != '\n')
                fprintf(out, "%c", c);
            tmp = c;
        }
    }
    else if (!in)
        perror("input.txt");
    else if (!out)
        perror("output.txt");

    if (in) fclose(in);
    if (out) fclose(out);
}

int recursive_max(int* arr, int n)
{
    if (n == 1)
        return arr[0];
    int max = recursive_max(arr, n - 1);
    return arr[n - 1] > max ? max : arr[n - 1];
}

int recursive_odd(int* arr, int n)
{
    if (n == 0)
        return -1;
    if (arr[n - 1] % 2 == 1)
        return arr[n - 1];
    return recursive_odd(arr, n - 1);
}

double recursive_pi(int n)
{
    if (n == 1)
        return 4.0;
    double sign = n % 2 == 0 ? -1.0 : 1.0;
    return recursive_pi(n - 1) + ((4 / (2 * n - 1)) * sign);
}

