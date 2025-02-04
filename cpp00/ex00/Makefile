# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 18:44:45 by ykai-yua          #+#    #+#              #
#    Updated: 2025/02/04 18:58:33 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for megaphone.cpp

# Compiler
CC = c++

# Compiler flags
CCFLAGS = -Wall -Wextra -std=c++98

# Source file
SRC = megaphone.cpp

# Executable name
NAME = megaphone

# Default target
all: $(NAME)

# Link the object file to create the executable
$(NAME): $(SRC)
	$(CC) $(CCFLAGS) $(SRC) -o $(NAME)

# Clean up build files
clean:
	rm -f $(NAME)

# Run the program
run: $(NAME)
	./$(NAME)

.PHONY: all clean run