# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 09:06:08 by mfassad           #+#    #+#              #
#    Updated: 2025/09/13 14:30:52 by mfassad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

# Source files
SRCS = main.c utils.c path.c parse.c child_p.c ft_split_sp.c
OBJS = $(SRCS:.c=.o)

# Bonus source files
BONUS_SRCS = main_bonus.c utils_bonus.c execute_bonus.c child_p_bonus.c ft_split_sp_bonus.c path_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

# Build main program
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile .c to .o
%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus rule
bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(LIBFT)

# Clean object files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

# Full clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
