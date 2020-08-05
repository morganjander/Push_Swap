#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av){

    if (ac < 3){
        return 0;
    }

    if(valid_input(ac, av)){
        my_stack *stack_a = NULL;
        my_stack *stack_b = NULL;
        make_stack(ac, av, &stack_a);
    
    
        char *line;
        int fd = 0;
        int i;
        int bad_op = 0;
        i = (get_next_line(fd, &line));
        if (i){
            while (i == 1){
                if(!check_op(line)){
                    ft_putendl(ERROR);
                    free_stack(stack_a);
                    free_stack(stack_b);
                    free(line);
                    return 0;
                }
                do_op(line, &stack_a, &stack_b);
                free(line);
                i = (get_next_line(fd, &line));
            }
        }
        if (!bad_op){
                if(is_sorted(stack_a) && stack_b == NULL){
                ft_putendl(OK);
                } 
                else {
                    ft_putendl(KO);
                }
            }else {
                ft_putendl(ERROR);
            }
        free_stack(stack_a);
        free_stack(stack_b);
    
    } else {
        ft_putendl(ERROR);
        return 0;
    }
	return (1);

}

