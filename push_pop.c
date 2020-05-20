#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

my_stack    *new_node(int val){
    my_stack *stack;
    stack = (my_stack*)malloc(sizeof(my_stack));
    (stack)->num = val;
    (stack)->next = NULL;
    return (stack);
}

my_stack    *append(my_stack *end, my_stack *new){
    end->next = new;
    return (end->next);
}

void print_stack(my_stack *start){
    my_stack *ptr = NULL;
    ptr = start;
    while(ptr != NULL) {
      ft_putnbr(ptr->num);
      ft_putchar('\n');
      ptr = ptr->next;
  }
}

void    free_stack(my_stack *start){
    my_stack *ptr;
    ptr = start;
    while(ptr != NULL){
        start = ptr;
        ptr = ptr->next;
        free(start);

    }
}

void    push(my_stack **head, int val){
    my_stack *node;
    node = new_node(val);
    node->next = *head;
    *head = node;
}

void     fuckyou(void){
    ft_putchar('F');
    ft_putchar('U');
    ft_putchar('C');
    ft_putchar('K');
    ft_putchar('\n');
    ft_putchar('Y');
    ft_putchar('O');
    ft_putchar('U');
    ft_putchar('\n');
}