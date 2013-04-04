/* Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to
   use a function for conversion. */

#include <stdio.h>

float celsius(float fahr);

int main()
{
	float fahr;
	float lower, upper, step;

	lower = 0;	/* lower limit of temperature scale */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;
	printf("%3c %6c\n", 'F', 'C');
	while (fahr <= upper) {
		printf("%3.0f %6.1f\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
	return 0;
}

float celsius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}
