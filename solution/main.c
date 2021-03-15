#include <stdio.h>
#include <math.h>
#include <string.h>
#include "cw5.h"
#include "cw4.h"
#include "cw3.h"
#include <stdbool.h>

int main()
{
	printf("%s\n",checkIfPalindrome(101) ? "true" : "false");
	printf("%s\n",checkIfPalindrome(1101) ? "true" : "false");
	printf("%s\n",checkIfPalindrome(1223221) ? "true" : "false");
	printf("%s\n",checkIfPalindrome(1) ? "true" : "false");
	printf("%s\n",checkIfPalindrome(111) ? "true" : "false");

	printf("%d\n", reverseAndAdd(195));
}