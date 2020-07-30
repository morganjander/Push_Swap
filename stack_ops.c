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

void    do_op(char *line, my_stack **stack_a, my_stack **stack_b){
    
    if (line[0] == 's' && line[1] == 'a'){
        op_sa(stack_a);
    }

    else if (line[0] == 's' && line[1] == 'b'){
        op_sa(stack_b);
    }

    else if (line[0] == 's' && line[1] == 's'){
        op_sa(stack_a);
        op_sa(stack_b);
    }

    else if (line[0] == 'r' && line[1] == 'a'){
        op_ra(stack_a);
    }

    else if (line[0] == 'r' && line[1] == 'b'){
        op_ra(stack_b);
    }
    

    else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a'){
        op_rra(stack_a);
        
    }
    else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'){
        op_rra(stack_b);
        
    }
    else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'){
        op_rra(stack_a);
        op_rra(stack_b);
        
    }
    else if (line[0] == 'r' && line[1] == 'r'){
        op_ra(stack_a);
        op_ra(stack_b);
    }
    else if (line[0] == 'p' && line[1] == 'b'){
        op_pb(stack_a, stack_b);
        
    }
    else if(line[0] == 'p' && line[1] == 'a'){
        op_pb(stack_b, stack_a);
    }
}

void op_sa(my_stack **start){
    if (*start == NULL || (*start)->next == NULL){
        return;
    }
    my_stack *ptr;
    ptr = (*start)->next;
    swap(&ptr, start);
}

void op_ra(my_stack **start){//top goes to bottom
     if (*start == NULL || (*start)->next == NULL){
        return;
    }
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
     if (*start == NULL || (*start)->next == NULL){
        return;
    }
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

void op_pb(my_stack **stack_a, my_stack **stack_b){//top of a to top of b
    if (*stack_a == NULL){
        return;
    }
    my_stack *ptra = *stack_a;
    my_stack *ptrb;
    ptrb = new_node(ptra->num);
    if(*stack_b == NULL){
        *stack_b = ptrb;
    } else {
        ptrb->next = *stack_b;
        *stack_b = ptrb;
    }
    if(stack_len(stack_a) == 1) {
         free(*stack_a);
         *stack_a = NULL;
    } else {
        ptra = ptra->next;
        free(*stack_a);
        *stack_a = ptra;
    }
}

void    swap(my_stack **x, my_stack **y){
    int tmp;
    tmp = (*x)->num;
    (*x)->num = (*y)->num;
    (*y)->num = tmp;
}

void print_do_op(char *s, my_stack **stack_a, my_stack **stack_b){
    ft_putendl(s);
    do_op(s, stack_a, stack_b);
}