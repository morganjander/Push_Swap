#include "./libft/libft.h"
#include "./push_swap.h"

void    pa(stack **a, stack **b){
    stack *node;
    
    if(!(*b)){
        return;
    }
    node = malloc(sizeof(stack)); //should you cast here?
    node->num = pop(b);
    if(!(a)){
        node->next = NULL;
    } else {
        node->next = *a;
    }
    *a = node;
}

void    pb(stack **a, stack **b){
    stack *node;
    if(!(*a)){
        return;
    }
    node = malloc(sizeof(stack));
    node->num = pop(a);
    if(!(b)) {
        node->next = NULL;
    } else {
        node->next = *b;
    }
    *b = node;
}