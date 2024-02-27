# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 14:52:53 by cmansey           #+#    #+#              #
#    Updated: 2024/02/05 14:52:53 by cmansey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
