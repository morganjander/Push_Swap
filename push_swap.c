#include "libft/libft.h"
#include "push_swap.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int   main(int ac, char **av){

   if (ac < 3){
        return 0;
  }
  if(validate_input(ac, av)){
    my_stack *stack_a = NULL;
    my_stack *stack_b = NULL;
    make_stack(ac, av, &stack_a);

   sort(&stack_a, &stack_b, ac - 1);
   free_stack(stack_a);
   free_stack(stack_b);
  } 
  return 1;
}

