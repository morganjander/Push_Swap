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
  ft_putchar('\n');
}

void    print_stacks(my_stack *stack_a, my_stack *stack_b){
    if(stack_a) {
        print_stack(stack_a);
    }
    if(stack_b) {
        print_stack(stack_b);
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

int stack_len(my_stack **head){
    int len = 0;
    if(*head != NULL){
        len = 1;
        my_stack *ptr;
        ptr = *head;
        while(ptr->next != NULL){
            len++;
            ptr = ptr->next;
        }
    }
    return len;
}

int is_sorted(my_stack *start){
    int n = 0;
    my_stack *ptr = NULL;
    ptr = start;
    while(ptr != NULL) {
      if(ptr->num < n){
          return 0;
      } else {
          n = ptr->num;
      }
      ptr = ptr->next;
  }
  return 1;
}