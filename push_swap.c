#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
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

   if(ac == 4) {
     sort_3(&stack_a, &stack_b);
   }
   else if (ac == 5 || ac == 6){
     sort_4_or_5(&stack_a, &stack_b);
   }
   else {
     sort_100(&stack_a, &stack_b, ac - 1);
   }
   
    free_stack(stack_a);
    free_stack(stack_b);
  } 
  return 1;
}

