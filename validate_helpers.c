#include "libft/libft.h"
#include "push_swap.h"

int		valid_input_string(char **av)
{
	static char	**arr;
	int			i;

	arr = ft_strsplit(av[1], ' ');
	i = 0;
	if (!only_digits(av[1]))
		return (0);
	while (arr[i])
	{
		if (int_overflows(arr[i]))
            return (0);
		i++;
	}
	return (1);
}

int		valid_input_int(int ac, char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (int_overflows(av[i])){
			return (0);
        }
            
		if (!only_digits(av[i])){
			return (0);
        }
            
		i++;
	}
	if (found_dupes(ac, av)){
		return (0);
    }
    return (1);
}

int		only_digits(char *str)
{
	while (*str)
	{
		if (*str == '-')
			str++;
		if (!(ft_isdigit(*str)) && (!(ft_iswhitespace(*str))))
			return (0);
		str++;
	}
	return (1);
}

int found_dupes(int ac, char **av){
  int x = 1;
  int y = 0;
  while(x < ac){
    y = x + 1;
    while(y < ac){
      if(ft_atoi(av[x]) == ft_atoi(av[y])){
        return 1;
      }
      y++;
    }
    x++;
  }
    return 0;
}

int		int_overflows(const char *str)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		(*str == '-') ? (neg = -1) : 1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		if (neg == 1)
			if (res > 2147483647)
				return (1);
		str++;
	}
	res *= neg;
	if (res < -2147483647)
		return (1);
	return (0);
}

int		check_op(char *line)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "sb"))
		return (1);
	else if (ft_strequ(line, "pa") || ft_strequ(line, "pb"))
		return (1);
	else if (ft_strequ(line, "ss"))
		return (1);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rb"))
		return (1);
	else if (ft_strequ(line, "rr") || ft_strequ(line, "rrr"))
		return (1);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrb"))
		return (1);
	return (0);
}
