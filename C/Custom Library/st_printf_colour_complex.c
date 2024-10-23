#include "stratocaster.h"

int	ptrlen(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	putptr(uintptr_t num)
{
	if (num >= 16)
	{
		putptr(num / 16);
		putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			st_putchar_fd((num + '0'), 1);
		else
			st_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	printf_pointer(unsigned long long out)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (out == 0)
		len += write(1, "0", 1);
	else
	{
		putptr(out);
		len += ptrlen(out);
	}
	return (len);
}

int	numlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	printf_udec(unsigned int out)
{
	int		len;
	char	*num;

	len = 0;
	if (out == 0)
		len += write(1, "0", 1);
	else
	{
		num = uitoa(out);
		len += printf_string(num);
		free(num);
	}
	return (len);
}

int	hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	puthex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		puthex(num / 16, format);
		puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			st_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				st_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				st_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	printf_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		puthex(num, format);
	return (hexlen(num));
}
