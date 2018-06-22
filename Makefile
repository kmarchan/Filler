
NAME= fluffy.filler

all:	$(NAME)

LIB: 
	make re -C ./libft_gnl/

INCLUDES= -I ./libft_gnl/includes

SRC=	get_info.c 

$(NAME): LIB
	gcc -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) get_info.o -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
