#include "libft/libft.h"
#include "push_swap.h"

int   validate_input(int ac, char **av){
  int ret = 0;
  if (ac < 3 || found_dupes(ac, av)){
    return ret;
  }
  ret = 1;
  return ret;
}

int			valid_input(int ac, char **av)
{
	if (ac == 2)
	{
		if (!valid_input_string(av))
			return (0);
	}
	else if (ac > 2)
	{
		if (!valid_input_int(ac, av))
			return (0);
	}
	return (1);
}

