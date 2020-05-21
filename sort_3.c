#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void    sort_3(my_stack **stack_a){
    if(is_sorted(*stack_a)){
        return;
    }
    int top, mid, bot;
    my_stack *ptr;
    ptr = *stack_a;

    top = ptr->num;
    ptr = ptr->next;
    mid = ptr->num;
    ptr = ptr->next;
    bot = ptr->num;
    
    if(top > mid && mid < bot && bot > top){
        op_sa(stack_a);
        ft_putendl(SA);
    }

    else if(top > mid && mid > bot && bot < top){
        op_sa(stack_a);
        ft_putendl(SA);
        op_rra(stack_a);
        ft_putendl(RRA);
    }

    else if(top > mid && mid < bot && bot < top){
        op_ra(stack_a);
        ft_putendl(RA);
    }

    else if(top < mid && mid > bot && bot > top){
        op_sa(stack_a);
        ft_putendl(SA);
        op_ra(stack_a);
        ft_putendl(RA);
    }
    else {
        op_rra(stack_a);
        ft_putendl(RRA);
    }
}

void    sort_5(my_stack **stack_a, my_stack **stack_b){
    int pos;
    while(stack_len(stack_a) > 3){
        op_pb(stack_a, stack_b);
        ft_putendl(PB);
    }
    sort_3(stack_a);

    while(*stack_b){
        pos = find_pos(*stack_a, (*stack_b)->num);
        insert(pos, stack_a, stack_b);
    }
}

int     find_pos(my_stack *start, int n){//only for sorted stacks!
   my_stack *ptr = start;
   int pos = 0;
   if (n < ptr->num){
       return pos;
   }
   while (n > ptr->num && ptr->next != NULL){
           ptr = ptr->next;
           pos++;
       }
    if(n > ptr->num){
        pos++;
    }
   return pos;
}

void    insert(int pos, my_stack **stack_a, my_stack **stack_b){
    int i = stack_len(stack_a) - pos;
    switch(i){
        case 0:
        op_pb(stack_b, stack_a);
        ft_putendl(PA);
        op_ra(stack_a);
        ft_putendl(RA);
        return;
        case 1:
        op_rra(stack_a);
        ft_putendl(RRA);
        op_pb(stack_b, stack_a);
        ft_putendl(PA);
        op_ra(stack_a);
        ft_putendl(RA);
        op_ra(stack_a);
        ft_putendl(RA);
        return;
        case 2:
        op_rra(stack_a);
        ft_putendl(RRA);
        op_rra(stack_a);
        ft_putendl(RRA);
        op_pb(stack_b, stack_a);
        ft_putendl(PA);
        op_ra(stack_a);
        ft_putendl(RA);
        op_ra(stack_a);
        ft_putendl(RA);
        op_ra(stack_a);
        ft_putendl(RA);
        return;
        case 3:
        op_pb(stack_b, stack_a);
        ft_putendl(PA);
        op_sa(stack_a);
        ft_putendl(SA);
        return;
        case 4:
        op_pb(stack_b, stack_a);
        ft_putendl(PA);
        return;
        default:
        return;

    }
}