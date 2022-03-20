#include "push_swap.h"

int   push_stack(stack *stackA, stack *stackB, char *inst)
{
    t_node *node;

    if((node = pop_el(stackA)))
    {
        print_instruction(inst);
        push_el(stackB, node->value);
        free(node);
        return (1);
    }
    return (0);
}

int    rotate_el(stack *stack, char *inst)
{
    t_node *node;
    t_node *tmp_stack;
    t_node *tmp_el;

    tmp_stack = *stack;
    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    tmp_el = pop_el(stack);
    node->value = tmp_el->value;
    node->index = tmp_el->index;
    node->flag = tmp_el->flag;
    node->sub_index = tmp_el->sub_index;
    node->length = 1;
    node->next = NULL;
    while (tmp_stack->next != NULL)
        tmp_stack = tmp_stack->next;
    tmp_stack->next = node;
    free(tmp_el);
    print_instruction(inst);
    return (1);
}

int     reverse_rotate_el(stack *stack, char *inst)
{
    t_node *node;
    t_node *tmp;

    tmp = *stack;
    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    node->value = tmp->next->value;
    node->index = tmp->next->index;
    node->sub_index = tmp->next->sub_index;
    node->length = 1;
    node->next = *stack;
    free(tmp->next);
    tmp->next = NULL;
    *stack = node;
    print_instruction(inst);
    return (1);
}

void    swap_el(stack *stack, char *inst)
{
    int tmp;
    
    tmp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
    print_instruction(inst);
}

void    print_stack(stack *stack)
{
    t_node *tmp;

    tmp = *stack;
    printf("----------------------------------------\n");
    while (tmp != NULL)
    {
        printf("Element:[%d] Pair:[%d] Index[%d] Length[%d] Flag[%d]\n ", tmp->value, tmp->sub_index, tmp->index, tmp->length, tmp->flag);
        tmp = tmp->next;
    }
}