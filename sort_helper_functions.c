#include "libft/libft.h"
#include "push_swap.h"
# include <stdio.h>

int find_min(my_stack *stack){
    int min = stack->num;
    while(stack){
        if (min > stack->num){
            min = stack->num;
        }
        stack = stack->next;
    }
    return min;
}

int find_max(my_stack *stack){
    int max = stack->num;
    while(stack){
        if (max < stack->num){
            max = stack->num;
        }
        stack = stack->next;
    }
    return max;
}

int     find_position(my_stack *start, int n){
    int pos = 0;
    while(start){
        if (n == start->num){
            return pos;
        }
        start = start->next;
        pos++;
    }
    return pos;
}

int	find_spot(my_stack *start, int n){
	int pos = 0;
	if (n > start->num){
            return pos;
        }
	pos++;
    while(start->next){
        if (n < start->num && n > start->next->num){
            return pos;
        }
        start = start->next;
        pos++;
    }
    return pos;
}

void	push_min_or_max_b(my_stack **a, my_stack **b, int repeat, int a_len)
{
	int i = 0;
	int min = find_min(*a);
	int max = find_max(*a);

	while (i < repeat)
	{
		if (find_position(*a, min) == 0 || find_position(*a, max) == 0)
		{
			print_do_op(PB, a, b);
			i++;
		}
		else if (find_position(*a, min) > a_len / 2 ||
		find_position(*a, max) > a_len / 2)
			print_do_op(RRA, a, b);
		else if (find_position(*a, min) < a_len / 2 ||
		find_position(*a, max) < a_len / 2)
			print_do_op(RA, a, b);
	}
}

void	push_max_a(my_stack **b, my_stack **a, int repeat)
{
	int i = 0;
	int max = find_max(*b);

	while (i < repeat)
	{
		if (find_position(*b, max) == 1)
		{
			print_do_op(PA, a, b);
			i++;
			if (*b)
				max = find_max(*b);
		}
		else if (find_position(*b, max) > stack_len(b) / 2)
			print_do_op(RRB, a, b);
		else if (find_position(*b, max) <= stack_len(b) / 2)
			print_do_op(RB, a, b);
	}
}

int moves_to_top(my_stack *stack, int num){
	int pos = find_position(stack, num);
	int len = stack_len(&stack);
	if (pos <= len / 2){
		return pos;
	}
	if (pos > len / 2){
		return (len - pos);
	}
	return 0;
}

int search_from_bottom(my_stack *stack, int low, int high){
	int len = stack_len(&stack);
	int ret = -1;
	int *array = (int *) malloc(sizeof(int) * len);
	int i = 0;
	while (i < len){
		array[i] = stack->num;
		stack = stack->next;
		i++;
	}
	i--;
	while (i > -1){
		if (array[i] >= low && array[i] <= high){
			ret = array[i];
			break;
		}
		i--;
	}
	free(array);
	return ret;
}

int search_from_top(my_stack *stack, int low, int high){
	while(stack){
		if (stack->num >= low && stack->num <= high){
			return stack->num;
		}
		stack = stack->next;
	}
	return -1;
}

int contains(my_stack *stack, int low, int high){
	while(stack){
		if (stack->num >= low && stack->num < high){
			return 1;
		}
		stack = stack->next;
	}
	return 0;
}

void check_b(my_stack **a, my_stack **b){
	int spot = find_spot(*b, (*a)->num);
	int i = 0;
	if (spot <= stack_len(b) / 2) {
		while (i < spot){
			print_do_op(RB, a, b);
			i++;
		}
		print_do_op(PB, a, b);
		i = 0;
		while (i < spot){
			print_do_op(RRB, a, b);
			i++;
		}
	}else {
		
		spot = stack_len(b) - spot;
		while (i < spot){
			print_do_op(RRB, a, b);
			i++;
		}
		print_do_op(PB, a, b);
		i = 0;
		while (i < (spot + 1)){	
			print_do_op(RB, a, b);
			i++;
		}
	}
}

void check_a_and_b(my_stack **a, my_stack **b, int n, int move){

	if (!(*b)){
		print_do_op(PB, a, b);
		return;
	}
	if (stack_len(b) == 1){
		if ((*a)->num < (*b)->num){
			print_do_op(PB, a, b);
			print_do_op(SB, a, b);
			return;
		}
		else {
			print_do_op(PB, a, b);
			return;
		}
	}

	int spot = find_spot(*b, n);
	int i = 0;
	if (move == 1 && spot <= stack_len(b) / 2) {//if n is hold_first, ie in the top half of stack a, and it belongs in the top half of stack b
		while (i < spot && moves_to_top(*a, n) != 0){
				print_do_op(RR, a, b);
				i++;
			}
			if (i < spot){
				while (i < spot){
					print_do_op(RB, a, b);
					i++;
				}
			} else if (moves_to_top(*a, n) != 0){
				while (moves_to_top(*a, n) != 0){
					print_do_op(RA, a, b);
				}
			}//this should move hold_first to top of stack a and make sure stack b is ready to receive it
			print_do_op(PB, a, b);
			i = 0;
			while (i < spot){
				print_do_op(RRB, a, b);
				i++;
			}
			return;
	}
   if (move == 2 && spot > stack_len(b) / 2) {//if n is hold_second, ie in the bottom half of stack a, and it belongs in the bottom half of stack b
		spot = stack_len(b) - spot;
		while (i < spot && moves_to_top(*a, n) != 0){
				print_do_op(RRR, a, b);
				i++;
			}
			if (i < spot){
				while (i < spot){
					print_do_op(RRB, a, b);
					i++;
				}
			} else if (moves_to_top(*a, n) != 0){
				while (moves_to_top(*a, n) != 0){
					print_do_op(RRA, a, b);
				}
			}//this should move hold_second to top of stack a and make sure stack b is ready to receive it
			print_do_op(PB, a, b);
			i = 0;
			while (i < (spot + 1)){
				print_do_op(RB, a, b);
				i++;
			}
			return;
	}   
	if (move == 1){
		while (moves_to_top(*a, n) != 0) {
            print_do_op(RA, a, b);
        }
        check_b(a, b);
		return;
	}       
	if (move == 2){
		while (moves_to_top(*a, n) != 0) {
                print_do_op(RRA, a, b);
            }
        check_b(a, b);
		return;
	}                 
}