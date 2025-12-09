# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 17:11:15 by mateferr          #+#    #+#              #
#    Updated: 2025/12/09 15:26:38 by mateferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

SRC = src/addContact.cpp src/Contact.cpp src/PhoneBook.cpp \
src/searchContact.cpp src/searchContactUtils.cpp main.cpp

INC_DIR = includes
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME) 

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) -I$(INC_DIR) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
