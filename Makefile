# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 13:53:38 by kmarchan          #+#    #+#              #
#    Updated: 2018/06/24 13:53:44 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fluffy.filler

all:	$(NAME)

LIB: 
	make re -C ./libft_gnl/

INCLUDES= -I ./libft_gnl/includes

SRC=	get_info.c get_map.c get_piece.c 

OBJ= $(SRC:.c=.o)

$(NAME): LIB
	gcc -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
