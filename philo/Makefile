NAME		= philo

CC			= clang -g
CFLAGS		= -Wall -Wextra -Werror -I include
RM			= rm -f

SRCS		= $(wildcard source/*/*.c)

OBJS		= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
