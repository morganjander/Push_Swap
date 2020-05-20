#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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

void    do_op(char *line, my_stack **start){
    printf("line is: %s\n", line);
    
    if (line[0] == 's' && line[1] == 'a'){
        op_sa(start);
    }

    if (line[0] == 'r' && line[1] == 'a'){
        op_ra(start);
        printf("ra op\n");
    }

    if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a'){
        op_rra(start);
        
    }
}

void op_sa(my_stack **start){
    my_stack *ptr;
    ptr = (*start)->next;
    swap(&ptr, start);
}

void op_ra(my_stack **start){//top goes to bottom
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

void op_rra(my_stack **start){//bottom goes to top
    my_stack *ptr;
    my_stack *ptr1;
    ptr = *start;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    int tmp = ptr->next->num; //last num
    ptr1 = ptr->next; //last pointer
    ptr->next = NULL;
    free(ptr1);
    ptr = *start;
    *start = new_node(tmp);
    (*start)->next = ptr;
}

void    swap(my_stack **x, my_stack **y){
    int tmp;
    tmp = (*x)->num;
    (*x)->num = (*y)->num;
    (*y)->num = tmp;
}