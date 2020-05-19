LIB 	= ./libft/libft.a
NAME 	= push_swap
FLAGS 	= -Wall -Werror -Wextra
OBJ 	= $(SRC:.c=.o)
SRC		= *.c

all: $(NAME)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) -L. $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: 
	rm -rf $(NAME) $(OBJ)