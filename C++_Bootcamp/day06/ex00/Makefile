# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 06:19:23 by cpauwels          #+#    #+#              #
#    Updated: 2018/06/05 06:23:46 by cpauwels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

LN = -lncurses

FLAGS = -Wall -Werror -Wextra

NAME = ft_retro

SRC = main.cpp Game.cpp ScreenObject.cpp

OBJ = $(SRC:.cpp=.o)

all:
	$(CC) -o $(NAME) $(SRC) $(LN) $(FLAGS)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
