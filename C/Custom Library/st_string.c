#include "stratocaster.h"

/* This function checks the length of a string. */
/* @param *string The string which will have its length checked. */
int	st_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

/* This function checks the length of a number (how many digits it has). */
/* @param *nb The number which will have its length checked. */
size_t	st_nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

/* This function converts a number into a string. */
/* @param n The number to convert into a string. */
char	*st_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = st_nb_len(n);
	nb = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}