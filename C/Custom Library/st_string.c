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