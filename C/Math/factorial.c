#include <stdio.h>

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