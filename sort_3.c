#include "libft/libft.h"
#include "push_swap.h"

void    sort_3(char **av){
    int top, mid, bot;
    top = ft_atoi(av[1]);
    mid = ft_atoi(av[2]);
    bot = ft_atoi(av[3]);
    
    if(top > mid && mid < bot && bot > top){
        ft_putchar('s');
        ft_putchar('a');
        ft_putchar('\n');
    }

    else if(top > mid && mid > bot && bot < top){
        ft_putchar('s');
        ft_putchar('a');
        ft_putchar('\n');
        ft_putchar('r');
        ft_putchar('r');
        ft_putchar('a');
        ft_putchar('\n');
    }

    else if(top > mid && mid < bot && bot < top){
        ft_putchar('r');
        ft_putchar('a');
        ft_putchar('\n');
    }

    else if(top < mid && mid > bot && bot > top){
        ft_putchar('s');
        ft_putchar('a');
        ft_putchar('\n');
         ft_putchar('r');
        ft_putchar('a');
        ft_putchar('\n');
    }
    else {
        ft_putchar('r');
        ft_putchar('r');
        ft_putchar('a');
        ft_putchar('\n');
    }
}