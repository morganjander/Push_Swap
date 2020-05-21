#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int   main(int ac, char **av){
  
  if(validate_input(ac, av)){
    my_stack *stack_a = NULL;
    my_stack *stack_b = NULL;
    make_stack(ac, av, &stack_a);
   // print_stack(stack_a);
    sort_5(&stack_a, &stack_b);
  //  print_stack(stack_a);
    free_stack(stack_a);
    free_stack(stack_b);
  } 
  return 1;
}

