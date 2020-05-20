#include "libft/libft.h"
#include "push_swap.h"

void    make_stack(int ac, char **av, my_stack **start){

  my_stack *new = NULL;
  my_stack *end = NULL;
  
  new = new_node(ft_atoi(av[1]));
  *start = end = new;
  int i = 2;
  while (i < ac){
      new = new_node(ft_atoi(av[i]));
      end = append(end,new);
      i++;
  }
}

void    do_op(char *line, int len, my_stack **start){
    if (ft_strnequ(line, "sa", len) == 1){
        op_sa(start);
    }
    if (ft_strnequ(line, "ra", len) == 1){
        op_ra(start);
    }
}

void op_sa(my_stack **start){
    my_stack *ptr;
    ptr = (*start)->next;
    swap(&ptr, start);
}

void op_ra(my_stack **start){
    my_stack *ptr;
    ptr = *start;
    int tmp = ptr->num;
    ptr = ptr->next;
    free(*start);
    *start = ptr;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node(tmp);
}

void    swap(my_stack **x, my_stack **y){
    int tmp;
    tmp = (*x)->num;
    (*x)->num = (*y)->num;
    (*y)->num = tmp;
}