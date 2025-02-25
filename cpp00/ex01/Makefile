# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:27:57 by ykai-yua          #+#    #+#              #
#    Updated: 2025/02/25 14:28:04 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = contact.cpp \
		phonebook.cpp \
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