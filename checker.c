#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int is_sorted(my_stack *start);

int main(int ac, char **av){

    my_stack *start = NULL;
    make_stack(ac, av, &start);
    
    
    char *line;
    int fd = 0;
    int i;
    int len = 0;
    i = (get_next_line(fd, &line));
	while (i == 1)
	{
        len = ft_strlen(line);
        do_op(line, len, &start);
        i = (get_next_line(fd, &line));
	}
    print_stack(start);
    if(is_sorted(start)){
        ft_putchar('O');
        ft_putchar('K');
        ft_putchar('\n');
    } else {
        ft_putchar('K');
        ft_putchar('O');
        ft_putchar('\n');
    }
    free_stack(start);
	return (0);

}

int is_sorted(my_stack *start){
    int n = 0;
    my_stack *ptr = NULL;
    ptr = start;
    while(ptr != NULL) {
      if(ptr->num < n){
          return 0;
      } else {
          n = ptr->num;
      }
      ptr = ptr->next;
  }
  return 1;
}

