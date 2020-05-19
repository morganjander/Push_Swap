#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "./libft/libft.h"
#define ERROR {ft_putstr_fd("Error\n", 2); return 0;}
typedef struct my_stack {
    int                 num;
    struct my_stack     *next;
}                   stack;

// rot_ops

void    pa(stack **a, stack **b);
void    pb(stack **a, stack **b);

//stack_ops

int     pop(stack **head);
void    print_stack(stack **list);
int     stack_len(stack **head);

//validate
void    push(stack **head, int val);
int     *get_order(stack **a);
stack   *norm(stack **a);

//not sure yet
void    free_list(stack *list);
void    str_to_stack(stack **a, char **av);
stack   *populate_stack(int ac, char **av);
#endif