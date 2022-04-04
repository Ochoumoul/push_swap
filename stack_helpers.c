/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:25 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/04 02:55:28 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min_number(t_stack *stack)
{
	int		min;
	t_node	*tmp_node;
	t_node	*tmp;

	tmp_node = *stack;
	min = tmp_node->value;
	while (tmp_node != NULL)
	{
		if (min >= tmp_node->value)
		{
			tmp = tmp_node;
			min = tmp_node->value;
		}
		tmp_node = tmp_node->next;
	}
	return (tmp);
}

t_node	*max_length(t_stack *stack)
{
	int		max;
	t_node	*tmp_node;
	t_node	*tmp;

	tmp_node = *stack;
	tmp = *stack;
	max = tmp_node->length;
	while (tmp_node->next != NULL)
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

t_node	*best_element(t_stack *stack)
{
	int		min;
	t_node	*tmp_node;
	t_node	*tmp;

	tmp_node = *stack;
	min = tmp_node->length;
	tmp = tmp_node;
	while (tmp_node != NULL)
	{
		if (min >= tmp_node->length)
		{
			tmp = tmp_node;
			min = tmp_node->length;
		}
		tmp_node = tmp_node->next;
	}
	return (tmp);
}

int	check_sorted_stack(t_stack *stack)
{
	t_node	*tmp;

	if (*stack)
	{
		tmp = *stack;
		while (tmp->next != NULL)
		{
			if (tmp->value < tmp->next->value)
				tmp = tmp->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
