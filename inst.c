#include "push_swap.h"

int    push_el(stack *stack, int value, int index)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = value;
    node->next = *stack;
    node->index = index;
    *stack = node;
    return (1);
}

t_node  *pop_el(stack *stack)
{
    if (*stack == NULL) return NULL;

    t_node *tmp;
    int result;
    
    tmp = *stack;
    result = (*stack)->value;
    *stack = (*stack)->next;
    free(tmp);
    return (*stack);
}

void    clear_stack(stack *stack)
{
    while (stack != NULL)
        pop_el(stack);
}

int     find_el(stack *stack, int value)
{
    t_node *tmp;

    tmp = *stack;
    if (!tmp)
        return (0);
    while (tmp != NULL)
    {
        if (tmp->value == value)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int   push_stack(stack *stackA, stack *stackB)
{
    t_node *el;

    el = pop_el(stackA);
    return (push_el(stackB,el->value, el->index));
}

int    rotate_el(stack *stack)
{
    t_node *node;
    t_node *tmp_stack;

    tmp_stack = *stack;

    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = 0;
    node->next = NULL;
    while (tmp_stack->next != NULL)
        tmp_stack = tmp_stack->next;
    tmp_stack->next = node;
    return (1);
}

int     reverse_rotate_el(stack *stack)
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
    node->next = *stack;
    tmp->next = NULL;

    *stack = node;
    return (1);
}

void    swap_el(stack *stack)
{
    int tmp;
    
    tmp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
}

void swap_both(stack *stackA, stack *stackB)
{
    swap_el(stackA);
    swap_el(stackB);
}

void    rotate_both(stack *stackA, stack *stackB)
{
    rotate_el(stackA);
    rotate_el(stackB);
}

void    reverse_rotate_both(stack *stackA, stack *stackB)
{
    reverse_rotate_el(stackA);
    reverse_rotate_el(stackB);
}

void    stack_error(stack *stack)
{
    printf("Stack Error:\n");
    clear_stack(stack);
    exit(0);
}

int main(void)
{
    stack a, b;
    int result;

    a = NULL;
    b = NULL;

    push_el(&a, 3, 0);
    push_el(&a, 9, 1);
    push_el(&a, 7, 2);
    push_el(&a, 6, 3);
    t_node *tmp;

    tmp = pop_el(&a);
    printf("%d\n", tmp->value);
    // clear_stack(&a);

    printf("===========Stack A=========\n");
    while (a != NULL)
    {
        printf("%d [%d]\n", a->value, a->index);
        a = a->next;
    }
    return (0);
}