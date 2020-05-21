#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int   validate_input(int ac, char **av){
  int ret = 0;
  if (ac < 3 || found_dupes(ac, av)){
    return ret;
  }
  ret = 1;
  return ret;
}

int found_dupes(int ac, char **av){
  int x = 0;
  int y = 0;
  while(x < ac){
    y = x + 1;
    while(y < ac){
      if(ft_atoi(av[x]) == ft_atoi(av[y])){
        return 1;
      }
      y++;
    }
    x++;
  }
    return 0;
}