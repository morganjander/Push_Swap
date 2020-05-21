LIB 	= ./libft/libft.a
FLAGS 	= -Wall -Werror -Wextra -ggdb3

PNAME 	= push_swap
CNAME	= checker

POBJ 	= push_swap.o push_pop.o sort_3.o stack_ops.o validate.o
COBJ	= checker.o stack_ops.o push_pop.o validate.o


all: $(PNAME) $(CNAME)

$(PNAME) : $(POBJ)
	gcc -o $(PNAME) $(POBJ) -L. $(LIB)

$(CNAME) : $(COBJ)
	gcc -o $(CNAME) $(COBJ) -L. $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: 
	rm -rf $(COBJ) $(POBJ) $(CNAME) $(PNAME)