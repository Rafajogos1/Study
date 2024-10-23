#include "stratocaster.h"

/* This function handles exponents (Example: 2^2)*/
/* @param num The base. */
/* @param power The exponent. */
int	ft_power(int num, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (num * ft_power(num, power - 1));
}