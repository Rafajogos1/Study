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

/* This function handles which conversions that "st_printf_colour" should do.*/
/* @param args The text that will be written.*/
/* @param format The character that tells what conversion to do. (Example: "%c" for characters) */
int	printf_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += printf_char(va_arg(args, int));
	if (format == 's')
		len += printf_string(va_arg(args, char *));
	if (format == 'p')
		len += printf_pointer(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		len += printf_num(va_arg(args, int));
	if (format == 'u')
		len += printf_udec(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		len += printf_hex(va_arg(args, unsigned int), format);
	if (format == '%')
		len += write(1, "%", 1);
	return (len);
}

/* A replica of "printf" that handles colour. */
/* This is to make it easier to change the colour withou the need of writing the ANSI codes manually. */
/* @param *color The color to write the text in. (Example: RED) */
/* @param *format The text to be written. */
/* @param ... The values which will be handled in "printf" conversions. */
int	printf_colour(const char *color, const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);

	if (color)
		write(1, color, st_strlen(color));
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += printf_format(args, format[i + 1]);
			i++;
		}
		else
			len += printf_char(format[i]);
		i++;
	}
	write(1, RESET, st_strlen(RESET));
	va_end(args);
	return (len);
}