# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/17 16:54:16 by mfassad           #+#    #+#              #
#    Updated: 2025/08/17 16:54:16 by mfassad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC   = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c src/parse.c src/utils.c \
       src/ops_swap.c src/ops_push.c src/ops_rotate.c src/ops_revrotate.c \
       src/small_sort.c src/index.c src/radix.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCS) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
