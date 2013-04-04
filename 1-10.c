/* Exercise 1-10. Write a program to copy its input to its output, replacing
   each tab by \t, each backspace by \b, and each backslash by \\. This makes
   tabs and backspaces visible in an unambiguous way. */

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
		if (c == '\t') {
			putchar('\\');
			putchar('t');
			print = 0;
		}
		if (c == '\b') {
			putchar('\\');
			putchar('b');
			print = 0;
		}
		if (c == '\\') {
			putchar('\\');
			putchar('\\');
			print = 0;
		}
		if (print == 1)
			putchar(c);
		print = 1;
	}
}
