# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 23:47:44 by ykai-yua          #+#    #+#              #
#    Updated: 2025/06/10 23:47:46 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Serializer.cpp \
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
