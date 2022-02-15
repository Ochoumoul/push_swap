#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

#define STACK_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} t_node;

typedef t_node *stack;

void    ft_print_inst(char inst,char s)
{
    ft_putchar(inst);
    ft_putchar(s);
    ft_putchar('\n');
}

int    push_el(stack *stack, int value, char s)
{
    t_node *node;

    ft_print_inst('p',s);
    // The function above will be responsible for printing the instruction.
    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = value;
    node->next = *stack;
    *stack = node;
    return (1); // 1 means that element have been pushed succesfully.
}

int     pop_el(stack *stack)
{
    if (*stack == NULL) return STACK_EMPTY;

    t_node *tmp = *stack;
    int result = (*stack)->value;
    *stack = (*stack)->next;
    free(tmp);
    return (result);
}

// The double swap function like ss should take 2 stacks as an argument.

void    swap_el(stack *stack, char s)
{
    int tmp;
    
    ft_print_inst('s',s);
    // The function above will be responsible for printing the instruction.
    tmp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
}

int    rotate_el(stack *stack, char s)
{
    t_node *node;

    ft_print_inst('r',s);
    // The function above will be responsible for printing the instruction.
    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = pop_el(stack);
    node->next = NULL;
    while (*stack != NULL)
        *stack = (*stack)->next;
    *stack = node;
    return (1);
}

int main(void)
{
    stack a, b;
    int result;

    a = NULL;
    b = NULL;

    push_el(&a, 5, 'a');
    push_el(&a, 17, 'a');
    push_el(&a, 45, 'a');
    push_el(&a, 51, 'a');
    push_el(&a, 12, 'a');
    push_el(&a, 19, 'a');
    rotate_el(&a, 'a');
    push_el(&b, 51, 'b');

    printf("===========Stack A=========\n");
    while ((result = pop_el(&a)) != STACK_EMPTY)
        printf("%d\n", result);
    printf("===========Stack B=========\n");
    while ((result = pop_el(&b)) != STACK_EMPTY)
        printf("%d\n", result);
    return (0);
}