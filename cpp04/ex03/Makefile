# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 17:00:59 by ykai-yua          #+#    #+#              #
#    Updated: 2025/04/24 17:11:48 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Final_Fantasy

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		AMateria.cpp \
		Cure.cpp \
		Ice.cpp \
		Character.cpp \
		MateriaSource.cpp
		

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re