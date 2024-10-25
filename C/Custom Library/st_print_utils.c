#include "stratocaster.h"

/* This function prints a "new line" character. */
/* Its purpose is just to make it quicker to write. */
void	print_nl(void)
{
	printf("\n");
}

/* This function writes a character to the provided file descriptor. */
/* @param c The character to be written. */
/* @param fd The file descriptor where to write the character. */
void	st_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* This function writes a string to the provided file descriptor. */
/* @param s The string to be written. */
/* @param fd The file descriptor where to write the string. */
void	st_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		st_putchar_fd(s[i], fd);
		i++;
	}
}