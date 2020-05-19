#include "libft/libft.h"
#include "push_swap.h"

void    push(stack **head, int val){
    stack *node;
    node = malloc(sizeof(stack));
    node->num = val;
    node->next = *head;
    *head = node;
}

int *get_order(stack **a){
    stack *tmp;
    stack *tmp1;
    int *order;
    int count;
    int i = -1;

    tmp = *a;
    order = (int*)malloc(sizeof(int) * stack_len(a));
    while (tmp){
        tmp1 = *a;
        count = 1;
        while(tmp1 != NULL){
            if (tmp->num > tmp1->num){
                count++;
            }
            tmp1 = tmp1->next;
        }
        order[++i] = count;
        tmp = tmp->next;
    }
    return(order);
}

stack *norm(stack **a){
    stack *ret;
    int *order;
    int i;

    ret = NULL;
    i = stack_len(a) - 1;
    order = get_order(a);
    while(i >= 0){
        push(&ret, order[i--]);
        free(order);
        return(ret);
    }

}