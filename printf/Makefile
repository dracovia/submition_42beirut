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

#include <unistd.h>
#include <stdarg.h>

NAME = libftprintf
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_printf.c ft_putstr.c
OBJ = $(SRC : .c = .o)

all : $(NAME)

$(NAME) : %(OBJ)
	ar rcs $(NAME) $(OBJ)	

%.o : %.cc
	$(CC) $(CFLAGS) -c $< -o $@
	
clean: 
	$(RM) $(OBJ)

fclean : clean 
	$(RM) $(NAME)
re : fclean all
