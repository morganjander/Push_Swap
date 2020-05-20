NAME	= libft.a
CFLAGS	=  -Wall -Werror -Wextra -c 
SRC		= *.c
OBJ 	= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	gcc $(CFLAGS) $(SRC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
