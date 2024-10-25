NAME = stratocaster.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = st_get_next_line.c \
		st_get_next_line_utils.c \
		st_math.c \
		st_print_utils.c \
		st_string.c

OBJS = $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			 all clean fclean re