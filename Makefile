# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 23:09:46 by ryaoi             #+#    #+#              #
#    Updated: 2017/03/28 00:24:04 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ryaoi.filler

DIR_LIB	= libft

LIBFT	= $(DIR_LIB)/libft.a

SRC		= main.c \
		  read_player.c \
		  ft_maps.c \
		  freetab.c \
		  first_move.c \
		  ft_check.c

OBJ		= $(SRC:.c=.o)

INCLUDE	= -Ifiller.h \
		  -I./libft/libft.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C $(DIR_LIB)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) ./libft/libft.a $(OBJ) $(INCLUDE) -ltermcap

clean:
	make clean -C $(DIR_LIB)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(DIR_LIB)
	rm -rf $(NAME)

re: fclean all
