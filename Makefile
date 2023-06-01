NAME					= libftprintf.a

SRCS					= ft_printf.c \
						  printf_function.c \
						  printf_conversion.c \
						  printf_conversion2.c

OBJS					= $(SRCS:%.c=%.o)

FLAGS					= -Wall -Wextra -Werror

$(NAME)		:	$(OBJS) ft_printf.h
			cc $(FLAGS) -c $(SRCS) -I./
			ar rc $(NAME) $(OBJS)

all	:	$(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all  clean fclean re