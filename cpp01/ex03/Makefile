# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 14:02:30 by ykai-yua          #+#    #+#              #
#    Updated: 2025/04/10 14:02:32 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = attack

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
		main.cpp

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