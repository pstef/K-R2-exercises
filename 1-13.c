/* Exercise 1-13. Write a program to print a histogram of the lengths of words
   in its input. It is easy to draw the histogram with the bars horizontal;
   a vertical orientation is more challenging. */

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define LIMIT 20

int main()
{
	int current, c, state;
	int i;
	float nwords[LIMIT], max;

	/* clear variables */
	current = max = 0;
	state = OUT;
	for (i = 0; i < LIMIT; ++i)
		nwords[i] = 0;

	/* collect data */
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				if (current > LIMIT)
					current = LIMIT;
				--current;
				++nwords[current];
				current = 0;
			}
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
		}
		if (state == IN)
			++current;
	}

	/* find maximum */
	for (i = 0; i < LIMIT; ++i)
		if (nwords[i] > max)
			max = nwords[i];
	max = max / 66.0;

	/* print output */
	for (i = 0; i < LIMIT; ++i) {
		if (i < LIMIT-1)
			printf("%3d: (%5.0f) ", i + 1, nwords[i]);
		else
			printf(">%d: (%5.0f) ", LIMIT, nwords[i]);
		for (nwords[i] = nwords[i] / max; nwords[i] > 1.0; --nwords[i])
			putchar('|');
		if (nwords[i] > 0.5)
			putchar(':');
		putchar('\n');
	}
}
