NAME		= philo

CC			= gcc -O3
CFLAGS		= -Wall -Wextra -Werror -I include
RM			= rm -f

SRCS		= \
			./source/action/action_log.c \
			./source/action/action_to_string.c \
			./source/fork/fork_destroy.c \
			./source/fork/fork_new.c \
			./source/game/game_destroy.c \
			./source/game/game_new.c \
			./source/game/game_start.c \
			./source/main/main.c \
			./source/philo/philo_destroy.c \
			./source/philo/philo_lifecycle.c \
			./source/philo/philo_new.c \
			./source/philo/philo_start.c \
			./source/philo/philo_terminate.c \
			./source/rules/rules_parse.c \
			./source/time/time_now.c \
			./source/time/time_sleep.c \
			./source/utils/utils_print.c \
			./source/utils/utils_printnbr.c \
			./source/utils/utils_strtoul.c

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
