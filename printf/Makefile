# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 12:07:45 by mfassad           #+#    #+#              #
#    Updated: 2025/07/03 13:38:55 by mfassad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# include <unistd.h>
# include <stdarg.h>

NAME    = libftprintf.a
SRC     = ft_printf.c ft_print_char.c ft_print_str.c ft_print_ptr.c \
          ft_print_int.c ft_print_unsigned.c ft_print_hex.c
OBJ     = $(SRC:.c=.o)
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus

