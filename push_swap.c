#include "libft/libft.h"
#include "push_swap.h"

void    free_list(stack *list){
    while(list){
        free(list);
        list = list->next;
    }
}

void    str_to_stack(stack **a, char **av){
    static char **args;
    int i;
    args = ft_strsplit(av[1], ' ');
    i = ft_wordcount(av[1], ' ') - 1;
    while (i >= 0){
        push(a, ft_atoi(args[i--]));
    }
}

stack   *populate_stack(int ac, char **av){
    stack *numbers = NULL;
    stack *normed = NULL;
    int i;
    if (ac == 2){
        str_to_stack(&numbers, av);
        normed = norm(&numbers);
        free_list(numbers);
        return (normed);
    }
    i = ac - 1;
    numbers = malloc(sizeof(stack));
    numbers->num = ft_atoi(av[i--]);
    numbers->next = NULL;
    while (i >= 1){
        push(&numbers, ft_atoi(av[i--]));
    }
    normed = norm(&numbers);
    free_list(numbers);
    return(normed);
}

int     main(int ac, char **av) {
    stack *a;
    stack *b;
    int len = 0;

    b = NULL;

}