# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 14:30:15 by romain            #+#    #+#              #
#    Updated: 2024/12/06 13:05:15 by rdupeux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES 		= cut.c gnl.c utils.c
SRC_DIR 		= srcs
OBJ_DIR 		= objs
SRC 			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ 			= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_debug		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=_debug.o))
HEADER_DIR 		= includes
CC				= cc
CFLAGS 			= -Wextra -Wall -Werror
NAME			= minignl.a
NAME_debug		= minignl_debug.a

all: $(NAME)

db: $(NAME_debug)

$(OBJ_DIR)/%_debug.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -g3 -I$(HEADER_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $@ $^

$(NAME_debug): $(OBJ_debug)
	ar -rcs $@ $^

$(OBJ_DIR):
	mkdir objs

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME_debug)

re: fclean all

.PHONY: all clean fclean re 