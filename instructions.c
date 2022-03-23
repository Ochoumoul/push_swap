/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:30:26 by ochoumou          #+#    #+#             */
/*   Updated: 2022/03/23 13:03:17 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stack *stackA, t_stack *stackB, char *inst)
{
	t_node	*node;

	node = pop_el(stackA);
	if (node)
	{
		print_instruction(inst);
		push_el(stackB, node->value);
		free(node);
		return (1);
	}
	return (0);
}

int	rotate_el(t_stack *stack, char *inst)
{
	t_node	*node;
	t_node	*tmp_stack;
	t_node	*tmp_el;

	tmp_stack = *stack;
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	tmp_el = pop_el(stack);
	node->value = tmp_el->value;
	node->index = tmp_el->index;
	node->flag = tmp_el->flag;
	node->sub_index = tmp_el->sub_index;
	node->length = 1;
	node->next = NULL;
	while (tmp_stack->next != NULL)
		tmp_stack = tmp_stack->next;
	tmp_stack->next = node;
	free(tmp_el);
	print_instruction(inst);
	return (1);
}

int	reverse_rotate_el(t_stack *stack, char *inst)
{
	t_node	*tmp_last;
	t_node	*tmp;

	tmp_last = *stack;
	while (tmp_last->next->next != NULL)
		tmp_last = tmp_last->next;
	tmp = tmp_last->next;
	tmp->next = *stack;
	tmp_last->next = NULL;
	*stack = tmp;
	print_instruction(inst);
	return (1);
}

void	swap_el(t_stack *stack, char *inst)
{
	int	tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	print_instruction(inst);
}

void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("Element:[%d] Index[%d]\n ", tmp->value, tmp->index);
		tmp = tmp->next;
	}
}
