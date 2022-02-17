#include <stdio.h>
#include "push_swap.h"

void    ft_print_inst(char *inst,char s)
{
    ft_putstr(inst);
    ft_putchar(s);
    ft_putchar('\n');
}

int    push_el(stack *stack, int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = value;
    node->next = *stack;
    *stack = node;
    return (1);
}

int     pop_el(stack *stack)
{
    if (*stack == NULL) return STACK_EMPTY;

    t_node *tmp;
    int result;
    
    tmp = *stack;
    result = (*stack)->value;
    *stack = (*stack)->next;
    free(tmp);
    return (result);
}

int   push_stack(stack *stackA, stack *stackB)
{
    int value;

    value = pop_el(stackA);
    return (push_el(stackB, value));
}

int    rotate_el(stack *stack)
{
    t_node *node;
    t_node *tmp_stack;

    tmp_stack = *stack;

    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = pop_el(stack);
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

int main(void)
{
    stack a, b;
    int result;

    a = NULL;
    b = NULL;

    push_el(&a, 3);
    push_el(&a, 9);
    push_el(&a, 7);
    push_el(&a, 6);
    reverse_rotate_el(&a);

    printf("===========Stack A=========\n");
    while ((result = pop_el(&a)) != STACK_EMPTY)
        printf("%d\n", result);
    return (0);
}