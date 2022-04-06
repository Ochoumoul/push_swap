/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:20 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/05 23:58:49 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_min_element(t_stack *stackA)
{
	int		list_half;
	int		i;
	t_node	*min;

	i = 0;
	min = min_number(stackA);
	list_half = stack_size(stackA) / 2;
	while ((*stackA)->value != min->value)
	{
		if (min->index > list_half)
			reverse_rotate_el(stackA, "rra\n");
		else
			rotate_el(stackA, "ra\n");
	}
}

void	sort_stack(t_stack *stackA, t_stack *stackB)
{
	int	size;

	index_stack(stackA);
	find_list(stackA);
	flag_elements(stackA);
	size = stack_size(stackA);
	while (size)
	{
		if ((*stackA)->flag == 1)
			rotate_el(stackA, "ra\n");
		else
			push_stack(stackA, stackB, "pb\n");
		size--;
	}
}

void	sort_all(t_stack *stackA, t_stack *stackB)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	sort_stack(stackA, stackB);
	while (stack_size(stackB) != 0)
	{
		index_stack(stackA);
		index_stack(stackB);
		pair_elements(stackA, stackB);
		search_best_element(stackA, stackB);
		flag_best_element(stackA, stackB);
		tmp_b = best_element(stackB);
		tmp_a = find_index(stackA, tmp_b->sub_index);
		smart_rr(stackA, stackB, tmp_a, tmp_b);
		smart_top(stackA, stackB, tmp_a, tmp_b);
		push_stack(stackB, stackA, "pa\n");
	}
	index_stack(stackA);
	top_min_element(stackA);
}
