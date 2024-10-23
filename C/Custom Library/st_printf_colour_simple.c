#include "stratocaster.h"

int	printf_char(char out)
{
	st_putchar_fd(out, 1);
	return (1);
}

int	printf_string(char *out)
{
	int	i;

	i = 0;
	if (out == NULL)
	{
		st_putstr_fd("(null)", 1);
		return (6);
	}
	while (out[i])
	{
		write(1, &out[i], 1);
		i++;
	}
	return (i);
}

int	printf_num(int out)
{
	int		len;
	char	*num;

	len = 0;
	num = st_itoa(out);
	len = printf_string(num);
	free(num);
	return (len);
}
