#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define PA "pa"
# define PB "pb"
# define OK "OK"
# define KO "KO"
# define ERROR "Error"

typedef struct  ps_stack
{
    int             num;
    struct ps_stack *next;
}  my_stack;

my_stack    *new_node(int val);
my_stack    *append(my_stack *end, my_stack *new);
void    print_stack(my_stack *start);
void    print_stacks(my_stack *stack_a, my_stack *stack_b);
void    free_stack(my_stack *start);
void    sort_3(my_stack **start);
void    sort_5(my_stack **stack_a, my_stack **stack_b);
void    make_stack(int ac, char **av, my_stack **start);
void    do_op(char *line, my_stack **stack_a, my_stack **stack_b);
void    op_sa(my_stack **start);
void    op_ra(my_stack **start);
void    op_rra(my_stack **start);
void    op_pb(my_stack **stack_a, my_stack **stack_b);
void    swap(my_stack **x, my_stack **y);
int     stack_len(my_stack **head);
int     found_dupes(int ac, char **av);
int     is_sorted(my_stack *start);
int     validate_input(int ac, char **av);
int     find_pos(my_stack *start, int n);
void    insert(int pos, my_stack **stack_a, my_stack **stack_b);
#endif