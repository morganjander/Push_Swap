LIB 	= ./libft/libft.a
FLAGS 	= -Wall -Werror -Wextra

PNAME 	= push_swap
CNAME	= checker

CSRC	= checker.c stack_ops.c push_pop.c validate.c validate_helpers.c $(LIB)
PSRC 	= push_swap.c push_pop.c sort.c stack_ops.c validate.c sort_helper_functions.c validate_helpers.c $(LIB)

all: $(CNAME) $(PNAME)

$(CNAME):
	gcc $(FLAGS) $(CSRC) -o $(CNAME)

$(PNAME):
	gcc $(FLAGS) $(PSRC) -o $(PNAME)

clean: 
	rm -rf $(PNAME) $(CNAME)

re: clean all