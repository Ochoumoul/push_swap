#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node {
    int value;
    int index;
    int pre_index;
    int length;
    int state;
    struct node *next;
} t_node;

#define STACK_EMPTY INT_MIN

typedef t_node *stack;

int     ft_atoi(const char *str);
void    ft_putchar(char c);
void    ft_putstr(char *str);
int    push_el(stack *stack, int value, int index);
t_node  *pop_el(stack *stack);
t_node	*min_number(stack *stack);
t_node	*max_length(stack *stack);
void    top_min_element(stack *stackA);
void    sort_element(stack *stack);
int     push_stack(stack *stackA, stack *stackB);
int     rotate_el(stack *stack);
int     reverse_rotate_el(stack *stack);
void    swap_el(stack *stack);
void    swap_both(stack *stackA, stack *stackB);
void    rotate_both(stack *stackA, stack *stackB);
void    reverse_rotate_both(stack *stackA, stack *stackB);
int     find_el(stack *stack, int value);
void     clear_stack(stack *stack);
void    stack_error(stack *stack);
void    print_stack(stack *stack);

#endif