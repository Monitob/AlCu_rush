# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/04 22:30:52 by jbernabe          #+#    #+#              #
#    Updated: 2014/03/07 21:10:21 by jbernabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = Puissance4

CFLAGS = -g --debug -Wall -Wextra -Werror

PATH_SRC = ./src
PATH_OBJ = ./objs
PATH_INC = ./includes

SRC = main.c 

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all:  lib $(NAME)

lib:
		@make -C libft

$(NAME): $(OBJ)
		@$(MAKE) -C libft
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./libft/  \
		-L/usr/lib/ -ltermcap -lft

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/, %.c)
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAGS) -o $@ -I $(PATH_INC) -Ilibft -c $<
	@echo Compiling object : $<

clean:
	#@$(MAKE) -C libft $@
	@rm -f $(OBJ)

fclean:	clean
#	@$(MAKE) -C libft $@
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: re, clean, fclean
