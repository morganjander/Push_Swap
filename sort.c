#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void    sort_3(my_stack **stack_a, my_stack **stack_b){
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
			print_do_op("pa", a, b);
		else if ((*b)->num == max)
		{
			print_do_op("pa", a, b);
			print_do_op("ra", a, b);
		}
	}
}

void	sort_20(my_stack **a, my_stack **b)
{
	int	range = 0;
	int i = 1;

	while (*a)
	{
		range += 15;
		while (i < range)
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
	push_max_a(b, a, i);
}

void sort_100(my_stack **a, my_stack **b){
    
    //int max = find_max(*a);
    int range = 100 / 5;
    int chunk_high = range;
    int chunk_low = 0;


    int hold_first;
    int hold_second;

    while (*a){
        while (contains(*a, chunk_low, chunk_high)){
            hold_first = search_from_top(*a, chunk_low, chunk_high);
            hold_second = search_from_bottom(*a, chunk_low, chunk_high);
            if (hold_first != hold_second){
                if (moves_to_top(*a, hold_first) <= moves_to_top(*a, hold_second)) {
                    while (moves_to_top(*a, hold_first) != 0) {
                        print_do_op(RA, a, b);
                    }
                    check_b(a, b);
                }

                else {
                    while (moves_to_top(*a, hold_second) != 0) {
                        print_do_op(RRA, a, b);
                    }
                    check_b(a, b);
                }
            }
            else {
                while (moves_to_top(*a, hold_first) != 0) {
                        print_do_op(RA, a, b);
                    }
                    check_b(a, b);
            }
    
        }
        chunk_high += range;
        chunk_low += range;
    }

    while (*b) {
        print_do_op(PA, a, b);
    }
        
   
    
    

}