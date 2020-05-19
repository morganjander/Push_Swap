LIB 	= libft/libft.a
NAME 	= push_swap
FLAGS 	= -Wall -Werror -Wextra -Wno-nonnull -Wno-nullability-completeness

SRC		= 	push_swap.c \
			stack_ops.c \
			rot_ops.c \
			validate.c  \
			$(LIB)

all: $(NAME)
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean: 
	rm -rf $(NAME)