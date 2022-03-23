/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:16 by ochoumou          #+#    #+#             */
/*   Updated: 2022/03/23 14:30:46 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_instruction(t_node *node, int size, int *desicion)
{
	int	insts;
	int	middle;

	insts = 0;
	middle = (size / 2);
	if (node->index <= middle)
	{
		insts = node->index;
		*desicion = 1;
	}
	else if (node->index > middle)
	{
		insts = size - node->index;
		*desicion = 2;
	}
	return (insts);
}

void	flag_best_element(t_stack *stackA, t_stack *stackB)
{
	t_node	*tmp;

	tmp = *stackB;
	while (tmp != NULL)
	{
		if (tmp->flag == find_index(stackA, tmp->sub_index)->flag)
			tmp->length = max(tmp->length, find_index(stackA, \
			tmp->sub_index)->length);
		else
			tmp->length = tmp->length + find_index(stackA, \
			tmp->sub_index)->length;
		tmp = tmp->next;
	}
}

void	search_best_element(t_stack *stackA, t_stack *stackB)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	tmp_b = *stackB;
	tmp_a = *stackA;
	while (tmp_b != NULL)
	{
		tmp_b->length = calculate_instruction(tmp_b, stack_size(stackB), \
		&tmp_b->flag);
		tmp_b = tmp_b->next;
	}
	while (tmp_a != NULL)
	{
		tmp_a->length = calculate_instruction(tmp_a, stack_size(stackA), \
		&tmp_a->flag);
		tmp_a = tmp_a->next;
	}
}

void	pair(t_stack *stack, t_node	*node)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (node->value > tmp->value && node->value < tmp->next->value)
		{
			node->sub_index = tmp->next->index;
			return ;
		}
		tmp = tmp->next;
	}
	if (node->value < (*stack)->value && node->value > tmp->value)
		node->sub_index = (*stack)->index;
	else
		node->sub_index = min_number(stack)->index;
}

void	pair_elements(t_stack *stackA, t_stack *stackB)
{
	t_node	*tmp;

	tmp = *stackB;
	while (tmp != NULL)
	{
		pair(stackA, tmp);
		tmp = tmp->next;
	}
}
