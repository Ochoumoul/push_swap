/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:42 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/11 03:24:24 by ochoumou         ###   ########.fr       */
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
	int	i;
	int	number;

	i = 0;
	argv = parse_input(argc, argv, &argc);
	if (argc >= 1)
	{
		i = argc - 1;
		while (i >= 0)
		{
			number = ft_atoi(argv[i]);
			if (!find_el(stack, number))
				push_el(stack, number);
			else
				stack_error(stack);
			i--;
		}
		free_table(argv);
		free(argv);
	}
	else
		validation_error(2, NULL);
}
