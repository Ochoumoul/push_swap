/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:53 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/01 14:33:08 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rr(t_stack *stackA, t_stack *stackB, t_node *nodeA, t_node *nodeB)
{
	if (nodeB->flag == nodeA->flag)
	{
		while (nodeB->value != (*stackB)->value && \
		nodeA->value != (*stackA)->value)
		{
			if (nodeB->flag == 2)
				reverse_rotate_both(stackA, stackB, "rrr\n");
			else
				rotate_both(stackA, stackB, "rr\n");
		}
	}
}

void	smart_top(t_stack *sa, t_stack *sb, t_node *na, t_node *nb)
{
	while (nb->value != (*sb)->value)
	{
		if (nb->flag == 2)
			reverse_rotate_el(sb, "rrb\n");
		else
			rotate_el(sb, "rb\n");
	}
	while (na->value != (*sa)->value)
	{
		if (na->flag == 2)
			reverse_rotate_el(sa, "rra\n");
		else
			rotate_el(sa, "ra\n");
	}
}
