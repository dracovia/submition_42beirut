# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/09 14:39:44 by mfassad           #+#    #+#              #
#    Updated: 2026/07/09 15:17:11 by mfassad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re