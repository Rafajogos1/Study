#include <stdio.h>

/* Factorial is a math operation in which we multiply a number by all the numbers before it that are greater than 0. Example: "5!" = 120 */
/* We can use recurssion to keep multiplying a number by any positive number that comes before it. */
/* Since the function is called continually until "n-1" is no longer a positive integer, we ensure that we multily every number before "n", including it. */

int	factorial(int n)
{
	if (n == 0)
		return(0);
	if (n < 0)
		return(-1);
	if ((n-1) > 0)
		n *= factorial(n - 1);
	return (n);
}

int	main()
{
	printf("%i\n", factorial(6));
}