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

COMP = clang++

FLAGS = -Wall -Werror -Wextra

NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
