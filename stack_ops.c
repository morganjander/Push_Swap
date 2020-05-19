#include "libft/libft.h"
#include "./push_swap.h"

int     pop(stack **head){
    stack *next_node;
    int     ret = -1;

    if(!(*head){
        return ret;
    }
    next_node = (*head)->next;
    ret = (*head)->num;
    free(*head);
    *head = next_node;
    return ret;
}

void    print_stack(stack **list){

    stack *node;
    node = *list;
    while(node){
        ft_putnbr(node->num);
        ft_putchar("\n");
        node = node->next;
    }
}

int stack_len(stack **head){
    stack *node;
    int count = 0;

    node = *head;
    while(node){
        node = node->next;
        count++;
    }
    return count;
}