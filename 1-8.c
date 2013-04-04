/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main()
{
	int c, nl, t, b;
	nl = 0;
	t = 0;
	b = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == '\t')
			++t;
		if (c == ' ')
			++b;
	}
	printf("nl: %d, t: %d, b: %d\n", nl, t, b);
}
