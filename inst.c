/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:15:54 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/24 18:30:12 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    push_el(stack *stack, int value, int index)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = value;
    node->index = index;
    node->length = 1;
    node->pre_index = -1;
    node->next = *stack;
    node->state = 0;
    *stack = node;
    return (1);
}

t_node  *pop_el(stack *stack)
{
    if (*stack == NULL) return NULL;

    t_node *tmp;
    t_node *el;
    
    el = (t_node *)malloc(sizeof(t_node));
    el->value = (*stack)->value;
    el->index = (*stack)->index;
    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    return (el);
}

void    clear_stack(stack *stack)
{
    while (*stack != NULL)
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

int stack_size(stack *stack)
{
    int size;
    t_node *tmp;

    size = 0;
    tmp = *stack;
    while (tmp != NULL)
    {
        size += 1;
        tmp = tmp->next;
    }
    return (size);
}

t_node	*min_number(stack *stack)
{
	t_node *tmp_node;
	t_node *min_node;

    min_node = (t_node *)malloc(sizeof(t_node));
    if (!min_node)
        return (NULL);
	tmp_node = *stack;
	min_node->value = tmp_node->value;
    min_node->index = tmp_node->index;
	while (tmp_node != NULL)
	{
		if (min_node->value > tmp_node->value)
        {
			min_node->value = tmp_node->value;
            min_node->index = tmp_node->index;
        }
		tmp_node = tmp_node->next;
	}
	return (min_node);
}

int   push_stack(stack *stackA, stack *stackB)
{
    t_node *node;

    if((node = pop_el(stackA)))
        return (push_el(stackB, node->value, node->index));
    return (0);
}

int    rotate_el(stack *stack)
{
    printf("ra\n");
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
    node->pre_index = -1;
    node->length = 1;
    node->next = NULL;
    while (tmp_stack->next != NULL)
        tmp_stack = tmp_stack->next;
    tmp_stack->next = node;
    return (1);
}

int     reverse_rotate_el(stack *stack)
{
    printf("rra\n");
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
    node->pre_index = -1;
    node->length = 1;
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

void    print_stack(stack *stack)
{
    t_node *tmp;

    tmp = *stack;
    while (tmp != NULL)
    {
        printf("Element:[%d] Length:[%d] Index[%d] Sub:[%d]\n", tmp->value, tmp->length, tmp->index,  tmp->pre_index);
        tmp = tmp->next;
    }   
}

// half = ROUND(number of elements / 2)
// if (index > half)
//      ra
// else
//      rra

void    top_min_element(stack *stackA)
{
    int     list_half;
    t_node *min;

	min = min_number(stackA);
    list_half = stack_size(stackA) / 2;
    while ((*stackA)->value != min->value)
    {
        if (min->index > list_half)
            rotate_el(stackA);
        else
            reverse_rotate_el(stackA);
    }
}

int max(int value1, int value2)
{
    if (value1 > value2)
        return (value1);
    else
        return (value2);
}

t_node	*max_length(stack *stack)
{
	t_node *tmp_node;
	t_node *max_length;

    max_length = (t_node *)malloc(sizeof(t_node));
    if (!max_length)
        return (NULL);
	tmp_node = *stack;
    max_length->length = tmp_node->length;
	while (tmp_node != NULL)
	{
		if (max_length->length < tmp_node->length)
        {
            max_length->length = tmp_node->length;
			max_length->value = tmp_node->value;
            max_length->index = tmp_node->index;
            max_length->pre_index = tmp_node->pre_index;
        }
		tmp_node = tmp_node->next;
	}
	return (max_length);
}

void    sort_element(stack *stack)
{
    t_node *tmp_i;
    t_node *tmp_j;

    tmp_i = (*stack)->next;
    while (tmp_i != NULL)
    {
        tmp_j = *stack;
        while (tmp_j != NULL)
        {
            if (tmp_i->value > tmp_j->value)
            {
                tmp_i->length = max(tmp_i->length, tmp_j->length + 1);
                tmp_i->pre_index = tmp_j->index;
            }
            tmp_j = tmp_j->next;
        }
        tmp_i = tmp_i->next;
    }
}

// void    first_phase(stack *stackA, stack *stackB)
// {
//     t_node *min_el;

//     min_el = min_number(stackA);
    
//     while ()
// }

// int main(void)
// {
//     stack a, b;
//     t_node *el;
//     t_node *el2;
//     int result;

//     a = NULL;
//     b = NULL;

//     push_el(&a, 3, 0);
//     push_el(&a, 9, 1);
//     push_el(&a, 6, 2);
//     push_el(&a, 1, 3);
//     push_stack(&a, &b);
//     push_stack(&a, &b);
    
//     printf("===========Stack A=========\n");
//     while ((el = pop_el(&a)) != NULL)
//         printf("%d [%d]\n", el->value, el->index);
//     printf("===========Stack B=========\n");
//     while ((el2 = pop_el(&b)) != NULL)
//         printf("%d [%d]\n", el2->value, el2->index);
//     return (0);
// }