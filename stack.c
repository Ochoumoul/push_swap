/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:47 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/01 14:54:54 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_el(t_stack *stack, int value)
{
	t_node	*node;

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

t_node	*pop_el(t_stack *stack)
{
	t_node	*tmp;
	t_node	*el;	

	if (*stack == NULL)
		return (NULL);
	el = (t_node *)malloc(sizeof(t_node));
	if (!el)
		return (NULL);
	el->value = (*stack)->value;
	el->index = (*stack)->index;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (el);
}

int	find_el(t_stack *stack, int value)
{
	t_node	*tmp;

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

void	clear_stack(t_stack *stack)
{
	while (*stack != NULL)
		pop_el(stack);
}

void	stack_error(t_stack *stack)
{
	write(1, "Stack Error:\n", 14);
	clear_stack(stack);
	exit(0);
}
