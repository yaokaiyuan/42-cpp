# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 18:44:45 by ykai-yua          #+#    #+#              #
#    Updated: 2025/02/04 18:46:00 by ykai-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for megaphone.cpp

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++98

# Source file
SRC = megaphone.cpp

# Executable name
TARGET = megaphone

# Default target
all: $(TARGET)

# Link the object file to create the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run