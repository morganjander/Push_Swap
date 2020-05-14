#include "../libft/libft.h"

void    pa(t_stack **a t_stack **b){
    t_stack *node;
    
    if(!(*b)){
        return;
    }
    node = malloc(sizeof(t_stack)); //should you cast here?
    node->num = pop(b);
    if(!(a)){
        node->next = NULL;
    } else {
        node->next = *a;
    }
    *a = node;
}