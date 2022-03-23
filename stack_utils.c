/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:42 by ochoumou          #+#    #+#             */
/*   Updated: 2022/03/23 12:56:27 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		size += 1;
		tmp = tmp->next;
	}
	return (size);
}

t_node	*find_index(t_stack *stack, int index)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	index_stack(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}
