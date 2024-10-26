#include "stratocaster.h"

/* This function handles factorials (Example: 5!) */
/* @param n The number to apply the calculations. */
int	st_factorial(int n)
{
	if (n == 0)
		return(0);
	if (n < 0)
		return(-1);
	if ((n-1) > 0)
		n *= factorial(n - 1);
	return (n);
}

/* This function handles exponents (Example: 2^2)*/
/* @param num The base. */
/* @param power The exponent. */
int	st_power(int num, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (num * st_power(num, power - 1));
}