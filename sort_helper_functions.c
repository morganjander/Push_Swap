#include "libft/libft.h"
#include "push_swap.h"

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

int contains_range(my_stack *stack, int range){
	while(stack){
		if(stack->num <= range){
			return 1;
		}
		stack = stack->next;
	}
	return 0;
}


void	push_max_a_r(my_stack **b, my_stack **a, int repeat)
{
	int i;
	int max;

	i = 0;
	max = find_min_or_max(*b, 1);
	while (i < repeat)
	{
		if (find_position_r(*b, max) == 1)
		{
			print_do_op(PA, a, b);
			i++;
			if (*b)
				max = find_min_or_max(*b, 1);
		}
		else if (find_position_r(*b, max) > list_length(b) / 2)
			print_do_op(RRB, a, b);
		else if (find_position_r(*b, max) <= list_length(b) / 2)
			print_do_op(RB, a, b);
	}
}

int		find_min_or_max(my_stack *stack, int type)
{
	int min_or_max;

	min_or_max = stack->num;
	if (type == 0)
	{
		while (stack)
		{
			if (min_or_max > stack->num)
				min_or_max = stack->num;
			stack = stack->next;
		}
	}
	else if (type == 1)
	{
		while (stack)
		{
			if (min_or_max < stack->num)
				min_or_max = stack->num;
			stack = stack->next;
		}
	}
	return (min_or_max);
}

int		find_position_r(my_stack *stack, int value)
{
	int position;

	position = 1;
	while (stack)
	{
		if (stack->num == value)
		{
			return (position);
		}
		stack = stack->next;
		position++;
	}
	return (0);
}

int		list_length(my_stack **head)
{
	my_stack *tmp;
	int		cnt;

	cnt = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}