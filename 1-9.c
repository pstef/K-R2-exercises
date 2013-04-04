/* Exercise 1-9. Write a program to copy its input to its output, replacing each
   string of one or more blanks by a single blank. */

#include <stdio.h>
/* no break
 * no &&
 * no ||
 * no return
 * no goto
 * no functions
 * no else
 * no comma operator
 */
int main()
{
	int c, print;
	print = 1;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (print == 1)
				putchar(c);
			print = 0;
		}
		if (c != ' ') {
			putchar(c);
			print = 1;
		}
	}
}
