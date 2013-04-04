/* Exercise 1-17. Write a program to print all input lines that are longer than
   80 characters. */

#include <stdio.h>
#define MAXLINE 82 /* maximum input line length */

/* POSIX 1003.1-2008 adds a getline() prototype to stdio.h, conflicting with the
   one below. In such case, rename this function or compile in C89 mode. */
int getline(char line[], int maxline);

int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	int c;

	while ((len = getline(line, MAXLINE)) > 0) {
		if (line[len-1] != '\n') {
			printf("%s", line);
			while ((c = getchar()) != EOF && c != '\n')
				putchar(c);
			putchar('\n');
		}
	}
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;
	c = '\0';

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
