#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int   main(int ac, char **av){
  my_stack *start = NULL;
  make_stack(ac, av, &start);
 // print_stack(start);
  free_stack(start);
  sort_3(av);
  
  return 1;
}

