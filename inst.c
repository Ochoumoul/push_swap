/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:15:54 by ochoumou          #+#    #+#             */
/*   Updated: 2022/03/06 19:47:32 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    push_el(stack *stack, int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = value;
    node->index = 1;
    node->length = 1;
    node->sub_index = -1;
    node->next = *stack;
    node->flag = 0;
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
    printf("pa\n");
    t_node *node;

    if((node = pop_el(stackA)))
        return (push_el(stackB, node->value));
    return (0);
}

t_node *last_element(stack *stack)
{
    t_node *tmp;

    tmp = *stack;
    while (tmp != NULL)
        tmp = tmp->next;
    return (tmp);
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
    node->sub_index = tmp_el->sub_index;
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
    node->sub_index = tmp->sub_index;
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
    printf("rr\n");
    rotate_el(stackA);
    rotate_el(stackB);
}

void    reverse_rotate_both(stack *stackA, stack *stackB)
{
    printf("rrr\n");
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
    printf("--------------------------------------------\n");
    while (tmp != NULL)
    {
        printf("Element:[%d] Index[%d] SubIndex[%d] Inst: [%d] Flag[%d]\n", tmp->value, tmp->index, tmp->sub_index, tmp->length, tmp->flag);
        tmp = tmp->next;
    }   
}

void    top_min_element(stack *stackA)
{
    int     list_half;
    t_node *min;

	min = min_number(stackA);
    list_half = stack_size(stackA) / 2;
    while ((*stackA)->value != min->value)
    {
        if (min->index > list_half)
            reverse_rotate_el(stackA);
        else
            rotate_el(stackA);
    }
}

t_node	*max_length(stack *stack)
{
    int     max;
    t_node *tmp_node;
    t_node *tmp;

	tmp_node = *stack;
    max = tmp_node->length;
	while (tmp_node != NULL)
	{
		if (max < tmp_node->length)
        {
            tmp = tmp_node;
            max = tmp_node->length;
        }
		tmp_node = tmp_node->next;
	}
	return (tmp);
}

t_node	*best_element(stack *stack)
{
    int     min;
    t_node *tmp_node;
    t_node *tmp;

	tmp_node = *stack;
    min = tmp_node->length;
    tmp = tmp_node;
	while (tmp_node != NULL)
	{
		if (min > tmp_node->length)
        {
            tmp = tmp_node;
            min = tmp_node->length;
        }
		tmp_node = tmp_node->next;
	}
	return (tmp);
}

void    index_stack(stack *stack)
{
    int i;
    t_node *tmp;

    tmp = *stack;
    i = 0;
    while (tmp != NULL)
    {
        tmp->index = i++;
        tmp = tmp->next;
    }
}

void    find_list(stack *stack)
{
    t_node *tmp_i;
    t_node *tmp_j;

    tmp_i = (*stack)->next;
    while (tmp_i != NULL)
    {
        tmp_j = *stack;
        while (tmp_j != tmp_i)
        {
            if (tmp_i->value > tmp_j->value)
            {
                tmp_i->length = max(tmp_i->length, tmp_j->length + 1);
                if (tmp_i->length <= tmp_j->length + 1)
                    tmp_i->sub_index = tmp_j->index;
            }
            tmp_j = tmp_j->next;
        }
        tmp_i = tmp_i->next;
    }
}

t_node *find_index(stack *stack, int index)
{
    t_node *tmp;

    tmp = *stack;
    while (tmp != NULL)
    {
        if (tmp->index == index)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

int    flag_elements(stack *stack)
{
    t_node *tmp_el;
    int i;

    i = 0;
    tmp_el = max_length(stack);
    while (tmp_el->sub_index != -1)
    {
        tmp_el->flag = 1;
        tmp_el = find_index(stack, tmp_el->sub_index);
        i++;
    }
    tmp_el->flag = 1;
    return (i + 1);
}

void    sort_stack(stack *stackA, stack *stackB)
{
    int     size;
    t_node *tmp;
    
    index_stack(stackA);
	find_list(stackA);
    flag_elements(stackA);
    size = stack_size(stackA);
    while (size > 0)
    {
        if ((*stackA)->flag == 1)
            rotate_el(stackA);
        else 
            push_stack(stackA, stackB);
        size -= 1;
    }
}

void    pair_elements(stack *stackA, stack *stackB)
{
    t_node *tmp_i;
    t_node *tmp_j;

    tmp_i = *stackB;
    while (tmp_i != NULL)
    {
        tmp_j = *stackA;
        while (tmp_j != NULL && tmp_j->next != NULL)
        {
            if (tmp_i->value > tmp_j->value && tmp_i->value < tmp_j->next->value)
            {
                tmp_i->sub_index = tmp_j->next->index;
            }
            tmp_j = tmp_j->next;
        }
        if (tmp_i->value < (*stackA)->value && tmp_j->value < tmp_i->value)
            tmp_i->sub_index = (*stackA)->index;
        tmp_i = tmp_i->next;
    }
    /// if the 
}

// !NEED: i'm going to need to find some sort of abrivation of this names. i mean the function names.
int calculate_instruction(t_node *node, int size, int *desicion)
{
    int middle;
    int insts;

    middle = size / 2;
    if (node->index <= middle)
    {
        insts = node->index;
        *desicion = 1; // Rotation
    }
    else if (node->index > middle)
    {
        insts = size - node->index;        
        *desicion = 2; // Reverse rotation
    }
    return (insts);
}

void    flag_best_element(stack *stackA, stack *stackB)
{
    t_node *tmp;
    int inst;

    tmp = *stackB;
    while (tmp != NULL)
    {
        if (tmp->flag == find_index(stackA ,tmp->sub_index)->flag)
            tmp->length = max(tmp->length, find_index(stackA, tmp->sub_index)->length);
        else
            tmp->length = tmp->length + find_index(stackA, tmp->sub_index)->length;
        tmp = tmp->next;
    }
    printf("--------stack A------\n");
    print_stack(stackA);
    printf("--------stack B------\n");
    print_stack(stackB);
}

void    search_best_element(stack *stackA, stack *stackB)
{
    // Now the object is to print how many instruction it will take to that element to the top.
    t_node *tmp_b;
    t_node *tmp_a;

    tmp_b = *stackB;
    tmp_a = *stackA;
    while (tmp_b != NULL)
    {
        tmp_b->length = calculate_instruction(tmp_b, stack_size(stackB), &tmp_b->flag);
        tmp_b = tmp_b->next;
    }
    while (tmp_a != NULL)
    {
        tmp_a->length = calculate_instruction(tmp_a, stack_size(stackA), &tmp_a->flag);
        tmp_a = tmp_a->next;
    }
}



void    top_pair_elements(stack *stackA, stack *stackB)
{
    t_node *tmp_b;
    t_node *tmp_a;
    t_node *track;

    track = *stackB;
    while (track != NULL)
    {
        index_stack(stackA);
        index_stack(stackB);
        pair_elements(stackA, stackB);
        search_best_element(stackA, stackB);
        flag_best_element(stackA, stackB);
        tmp_b = best_element(stackB);
        tmp_a = find_index(stackA, tmp_b->sub_index);
        if (tmp_b->flag == tmp_a->flag)
        {
            while (tmp_b->value != (*stackB)->value && tmp_a->value != (*stackA)->value)
            {
                if (tmp_b->flag == 2)
                    reverse_rotate_both(stackA, stackB);
                else
                    rotate_both(stackA, stackB);
            }
        }
        while (tmp_b->value != (*stackB)->value)
        {
            if (tmp_b->flag == 2)
                reverse_rotate_el(stackB); 
            else
                rotate_el(stackB);
        }
        while (tmp_a->value != (*stackA)->value)
        {
            if (tmp_a->flag == 2)
                reverse_rotate_el(stackA);
            else
                rotate_el(stackA);
        }
        push_stack(stackB, stackA);
        track = track->next;
    }
}

// !IDEA: what am thinking about is to add the desicsion to the node when am the doing the sort i can use the double and rotation and reverse 

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



/// Try to select the value that will be conveinent to the element am going to push to stack A
/// and try doing that by (NUMBERB - NUMBERA) = VAL that value should be the lowest possible value
/// in comparasion to all elements in the list.
/// And pair every element to the right one. Try to push that element in stack A and see how many
/// Instructions that is going to take and see how many instruction is going to take push the element
/// In stack B to the top compare them and push the best elements

/// !IDEA:
/// To find pair we will just have to find the element that can that element be in between.

/// !OPTIMAZATION:
/// DO not iterate in the hole list when trying to push the elements to stack A because
/// that is going to take more rotation instruction.

/// !IDEA:
/// Another idea we split the stack into half and we check weather the element belongs to the first half
/// Or the second half if the elements belongs to the first half check how far it is from the first element
/// in the stack. and if it belongs to the second half check how far is it from the last elements.


/// I need to figure out depending on the index how many instruction it will take to make the element i want in the top
/// or in the bottom