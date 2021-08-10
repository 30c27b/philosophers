# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 21:33:35 by ancoulon          #+#    #+#              #
#    Updated: 2021/08/10 14:30:28 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
