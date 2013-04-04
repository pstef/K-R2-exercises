/* Exercise 1-4. Write a program to print the corresponding Celsius to
   Fahrenheit table. */

#include <stdio.h>

int main()
{
	float celsius, fahr;
	float lower, upper, step;

	lower = -17.8;	/* lower limit of temperature scale */
	upper = 148.9;	/* upper limit */
	step = 20.0 * 5.0 / 9.0;	/* step size */

	celsius = lower;
	printf("%5c %4c\n", 'C', 'F');
	while (celsius <= upper) {
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%5.1f %4.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
