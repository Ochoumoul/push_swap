/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:42 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/01 13:03:57 by ochoumou         ###   ########.fr       */
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

void	insert_numbers(t_stack *stack, char **argv, int argc)
{
	int i;

	i = 0;
	argv = validate_args(argc, argv, &argc);
	i = argc - 1;
	while (i >= 0)
	{
		if (!find_el(stack, ft_atoi(argv[i])))
			push_el(stack, ft_atoi(argv[i]));
		else
			stack_error(stack);
		i--;
	}
}