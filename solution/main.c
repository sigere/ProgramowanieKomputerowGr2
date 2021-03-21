#include <stdio.h>
#include <math.h>
#include <string.h>
#include "cw5.h"
#include "cw6.h"
#include "cw4.h"
#include "cw3.h"
#include <stdbool.h>

int main()
 {
	/*printf("%s\n", checkIfPalindrome(101) ? "true" : "false");
	printf("%s\n", checkIfPalindrome(1101) ? "true" : "false");
	printf("%s\n", checkIfPalindrome(1223221) ? "true" : "false");
	printf("%s\n", checkIfPalindrome(1) ? "true" : "false");
	printf("%s\n", checkIfPalindrome(111) ? "true" : "false");

	printf("%d\n", reverseAndAdd(195));
	char string1[] = "ala Algieria alabama niea Ataman";
	startedWith('a', string1);
	char string2[] = "abcdefghijklmnopqrstuvwxyz";
	cipher(string2);
	char string3[] = "abc abcd abcde abc";
	printf("%d\n", longWordsCount(4, string3));

	printf("%f\n", bisection(0.0001, -2, 2));*/
	printf("%.12lf\n", pi(20));

	printf("%f", monte_carlo(100000000));
}