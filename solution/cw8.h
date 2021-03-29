#pragma once
#include <cstdio>
long long int factorial(long long int n);
int fibbonacii(int n);
float bisection(float(*function)(float), float precision, int a, int b);
char* to_binary(int dec);
int first_capital(char* text, int size, int n);
int w_len(char* c);
void hanoi(int n, char x, char y, char z, FILE *fp);