NAME					= libftprintf.a

SRCS					= ft_printf.c

BNS_SRCS				= 

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

FLAGS					= -Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
			cc $(FLAGS) -c $(SRCS) -I./
			ar rc $(NAME) $(OBJS)

all	:	$(NAME)

bonus	:	$(NAME)
		cc $(FLAGS) -c $(BNS_SRCS) -I./
		ar rc $(NAME) $(BNS_OBJS)

clean	:
		rm -f $(OBJS) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re