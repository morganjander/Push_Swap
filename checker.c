#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av){

    my_stack *stack_a = NULL;
    my_stack *stack_b = NULL;
    make_stack(ac, av, &stack_a);
    
    
    char *line;
    int fd = 0;
    int i;
    i = (get_next_line(fd, &line));
    if (i){
        while (i == 1){
            do_op(line, &stack_a, &stack_b);
            i = (get_next_line(fd, &line));
        }
        if(is_sorted(stack_a) && stack_b == NULL){
            ft_putendl(OK);
            } 
        else {
            ft_putendl(KO);
        }
        print_stack(stack_a);
    } else {
        ft_putendl(ERROR);
    }
	
    free_stack(stack_a);
	return (0);

}

