#include "libft/libft.h"
#include "push_swap.h"

void    sort(my_stack **a, my_stack **b, int len)
{
    if(is_sorted(*a)){
        return;
    }

    if (len == 3){
        sort_3(a, b);
        return;
    }
    if (len == 4 || len == 5){
        sort_4_or_5(a, b);
        return;
    }
    else {
        sort_20(a, b, len);
        return;
    }
  
}

void    sort_3(my_stack **stack_a, my_stack **stack_b){
    int top, mid, bot;
    my_stack *ptr;
    ptr = *stack_a;

    top = ptr->num;
    ptr = ptr->next;
    mid = ptr->num;
    ptr = ptr->next;
    bot = ptr->num;
    
    if(top > mid && mid < bot && bot > top){
        print_do_op(SA, stack_a, stack_b);
    }

    else if(top > mid && mid > bot && bot < top){
        print_do_op(SA, stack_a, stack_b);
        print_do_op(RRA, stack_a, stack_b);
    }

    else if(top > mid && mid < bot && bot < top){
       print_do_op(RA, stack_a, stack_b);
    }

    else if(top < mid && mid > bot && bot > top){
        print_do_op(SA, stack_a, stack_b);
        print_do_op(RA, stack_a, stack_b);
    }
    else {
        print_do_op(RRA, stack_a, stack_b);
    }
}

void	sort_4_or_5(my_stack **a, my_stack **b)
{
	int	min = find_min(*a);
	int max = find_max(*a);
    int repeat = stack_len(a) - 3;
	
	push_min_or_max_b(a, b, repeat, stack_len(a));
	if (!(is_sorted(*a)))
		sort_3(a, b);
	while (*b)
	{
		if ((*b)->num == min)
			print_do_op(PA, a, b);
		else if ((*b)->num == max)
		{
			print_do_op(PA, a, b);
			print_do_op(RA, a, b);
		}
	}
}


void	sort_20(my_stack **a, my_stack **b, int len)
{
	int	range;
	int i;
    int inc;

	range = 0;
    if (len >= 20 && len <= 100){
        inc = find_max(*a) / 6;
    } else {
        if (find_max(*a) == len) {
            inc = 36;
        } else {
            inc = find_max(*a) / 15;
        }
        
    }
    
	i = 1;
	while (*a)
	{
		range += inc;
		while (contains_range(*a, range))
		{
			if (!(*a))
				break ;
			if ((*a)->num <= range)
			{
				print_do_op(PB, a, b);
				i++;
			}
			else
				print_do_op(RA, a, b);
		}
	}
	i--;
	push_max_a_r(b, a, i);
}