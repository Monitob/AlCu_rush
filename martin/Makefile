# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 21:56:07 by mle-roy           #+#    #+#              #
#    Updated: 2014/03/08 23:15:20 by jbernabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=puissance4
VERSION=1.0.2
CFLAGS=-Wall -Werror -Wextra -g --debug
INCLUDES=-I ./libft/includes
LIBS=-L ./libft -l ft

SRC=alcu.c \
	can_i_stop.c \
	check_four.c \
	cmp_turn.c \
	get_map.c \
	human_turn.c \
	is_finish.c \
	make_check_play.c \
	play_something.c \
	printf_fn.c \

OBJ=$(SRC:.c=.o)

all: build $(NAME) finish

build:
	@($(MAKE) -C ./libft)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c puissance4.h ./libft/includes
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))
	@($(MAKE) -C ./libft fclean)

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v

