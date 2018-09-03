# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   TypeEnum.hpp                                       :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2018/08/06 06/19/11 by cpauwels          #+#    #+#             #
#   Updated: 2018/08/06 06/19/11 by cpauwels         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

CC = clang++

NAME = avm

SRC = Factory.cpp main.cpp Parse.cpp Actions.cpp 
 
FLAGS = -Wall -Werror -Wextra -std=c++11

OBJS = $(SRC:.cpp=.o)

$(NAME): all

all: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

clean:
	rm -f *.o

.cpp.o:
	${CC} ${FLAGS} -c $<

fclean: clean
	rm -f ${NAME}

re: fclean all