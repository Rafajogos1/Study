#include <stdio.h>
#include <stdlib.h>

void print_numbers(int *seq, int size)
{
	int	i = 0;

	while (i < size )
	{
		printf("%i, ", seq[i]);
		i++;
	}
	printf("%i.\n", seq[i]);
}

void	fibonacci(int n)
{
	int	i = 0;
	int	*seq;

	seq = malloc(sizeof(int) * (n + 1));
	if (n < 0 || n >= 47)
		return;
	while (i <= n)
	{
		switch (i)
		{
			case 0: seq[i] = 0; break;
			case 1: seq[i] = 1; break;
			default: seq[i] = (seq[i - 1] + seq[i - 2]);
		}
		i++;
	}
	print_numbers(seq, n);
	free(seq);
}

int	main()
{
	fibonacci(46); /* 46 is the max possible value for n within the limits of an int type variable. */
}