# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 06:40:21 by cpauwels          #+#    #+#              #
#    Updated: 2018/06/05 06:40:23 by cpauwels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMP = clang++

FLAGS = -Wall -Werror -Wextra

NAME = phonebook

SRC = main.cpp contact.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
