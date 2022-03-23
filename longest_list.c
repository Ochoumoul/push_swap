/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:06 by ochoumou          #+#    #+#             */
/*   Updated: 2022/03/23 12:54:57 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_list(t_stack *stack)
{
	t_node	*tmp_i;
	t_node	*tmp_j;

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

int	flag_elements(t_stack *stack)
{
	t_node	*tmp_el;
	int		i;

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
