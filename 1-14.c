/* Exercise 1-14. Write a program to print a histogram of the frequencies of
   different characters in its input. */

#include <stdio.h>

#define LIMIT 256

int main()
{
	int c;
	int i;
	float freq[LIMIT], max;

	/* clear variables */
	max = 0;
	for (i = 0; i < LIMIT; ++i)
		freq[i] = 0;

	/* collect data */
	while ((c = getchar()) != EOF) {
		++freq[c];
	}

	/* find maximum */
	for (i = 0; i < LIMIT; ++i)
		if (freq[i] > max)
			max = freq[i];
	max = max / 64.0;

	/* print output */
	for (i = 0; i < LIMIT; ++i) {
		if (freq[i] > 0) {
			if (i == ' ')
				printf("%5s: (%5.0f) ", "blank", freq[i]);
			else if (i == '\n')
				printf("%5s: (%5.0f) ", "\\n", freq[i]);
			else if (i == '\t')
				printf("%5s: (%5.0f) ", "\\t", freq[i]);
			else
				printf("%5c: (%5.0f) ", i, freq[i]);
			for (freq[i] = freq[i] / max; freq[i] > 1.0; --freq[i])
				putchar('|');
			if (freq[i] > 0.5)
				putchar(':');
			putchar('\n');
		}
	}
}
