# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 20:06:38 by ykai-yua          #+#    #+#              #
#    Updated: 2025/04/10 20:06:49 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Fixed.cpp \
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