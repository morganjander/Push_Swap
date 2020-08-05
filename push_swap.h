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
void    sort_3(my_stack **stack_a, my_stack **stack_b);
void    make_stack(int ac, char **av, my_stack **start);
void    print_do_op(char *s, my_stack **stack_a, my_stack **stack_b);
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

int     find_min(my_stack *stack);
int     find_max(my_stack *stack);
void	push_min_or_max_b(my_stack **a, my_stack **b, int repeat, int a_len);
void	push_max_a(my_stack **b, my_stack **a, int repeat);
int     find_position(my_stack *start, int n);

void	sort_4_or_5(my_stack **a, my_stack **b);

int		valid_input_string(char **av);
int		valid_input_int(int ac, char **av);
int		only_digits(char *str);
int		int_overflows(const char *str);
int		valid_input(int ac, char **av);
int		check_op(char *line);

void    sort(my_stack **a, my_stack **b, int len);
void	sort_20(my_stack **a, my_stack **b, int len);
void	push_max_a_r(my_stack **b, my_stack **a, int repeat);
int		find_min_or_max(my_stack *stack, int type);
int		find_position_r(my_stack *stack, int value);
int		list_length(my_stack **head);
int     contains_range(my_stack *stack, int range);
#endif