/* Stratocasters are cool */

#ifndef	STRATOCASTER_H
# define	STRATOCASTER_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

/* String constants */
# define	RESET	"\033[0m"
# define 	RED		"\033[0;31m"
# define 	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	MAGENTA	"\033[0;35m"
# define	CYAN	"\033[0;36m"

/* Math functions */
int		ft_power(int num, int power);

/* Printing utilities. */
void	print_nl(void);
void	st_putchar_fd(char c, int fd);
void	st_putstr_fd(char *s, int fd);
int		printf_colour(const char *color, const char *format, ...);

/* printf colour */
int		printf_format(va_list args, const char format);
int		printf_char(char out);
int		printf_string(char *out);
int		printf_num(int out);
int		ptrlen(uintptr_t num);
void	putptr(uintptr_t num);
int		printf_pointer(unsigned long long out);
int		numlen(unsigned	int num);
char	*uitoa(unsigned int n);
int		printf_udec(unsigned int out);
int		hexlen(unsigned	int num);
void	puthex(unsigned int num, const char format);
int		printf_hex(unsigned int num, const char format);

/* String */
int		st_strlen(const char *string);
size_t	st_nb_len(int nb);
char	*st_itoa(int n);

/* get_next_line */
char	*get_line(char *save);
char	*get_next_line(int fd, int BUFFER_SIZE);
char	*next_line(char *save);
char	*read_and_save(int fd, char *save, int BUFFER_SIZE);

/* get_next_line_utilities */
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(const char *s);

#endif