#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    int index;
    int sub_index;
    int length;
    int flag;
    struct node *next;
} t_node;


typedef t_node *stack;

int     ft_atoi(const char *str);
void    ft_putchar(char c);
int     push_el(stack *stack, int value);
void    clear_stack(stack *stack);
int     find_el(stack *stack, int value);
int     stack_size(stack *stack);
int     max(int value1, int value2);
t_node  *pop_el(stack *stack);
t_node	*min_number(stack *stack);
t_node	*max_length(stack *stack);
t_node	*best_element(stack *stack);
t_node  *find_index(stack *stack, int index);
void    sort_all(stack *stackA, stack *stackB);
void    top_pair_elements(stack *stackA, stack *stackB, t_node *nodeA, t_node *nodeB);
void    smart_double_rotation(stack *stackA, stack *stackB, t_node *nodeA, t_node *nodeB);
void    pair(stack *stack , t_node *node);
void    flag_best_element(stack *stackA, stack *stackB);
void    top_min_element(stack *stackA);
void    find_list(stack *stack);
void    index_stack(stack *stack);
void    sort_all(stack *stackA, stack *stackB);
int     check_sorted_stack(stack *stack);
int     flag_elements(stack *stack);
int     calculate_instruction(t_node *node, int size, int *desicion);
void    search_best_element(stack *stackA, stack *stackB);
void    sort_stack(stack *stackA, stack *stackB);
int     push_stack(stack *stackA, stack *stackB, char *inst);
void    pair_elements(stack *stackA, stack *stackB);
int     rotate_el(stack *stack, char *inst);
int     max(int value1, int value2);
int     reverse_rotate_el(stack *stack, char *inst);
void    swap_el(stack *stack, char *inst);
void	print_instruction(char *str);
void    swap_both(stack *stackA, stack *stackB);
void    rotate_both(stack *stackA, stack *stackB);
void    reverse_rotate_both(stack *stackA, stack *stackB);
int     find_el(stack *stack, int value);
void    clear_stack(stack *stack);
void    stack_error(stack *stack);
void    print_stack(stack *stack);

#endif