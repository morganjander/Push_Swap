#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct  ps_stack
{
    int             num;
    struct ps_stack *next;
}  my_stack;

my_stack    *new_node(int val);
void    push(my_stack **head, int val);
my_stack    *append(my_stack *end, my_stack *new);
void print_stack(my_stack *start);
void    free_stack(my_stack *start);
void     fuckyou(void);
void    sort_3(char **av);
void    make_stack(int ac, char **av, my_stack **start);
void    do_op(char *line, my_stack **start);
void    op_sa(my_stack **start);
void    op_ra(my_stack **start);
void    op_rra(my_stack **start);
void    swap(my_stack **x, my_stack **y);
#endif