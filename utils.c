/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:24:49 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/03 01:35:37 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	max(int value1, int value2)
{
	if (value1 > value2)
		return (value1);
	else
		return (value2);
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
}

void	print_instruction(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	validation_error(int code, char **numbers)
{
	if (code == 1)
	{
		print_instruction("Error inserting the numbers\n");
		free_table(numbers);
		exit(1);
	}
	else if (code == 2)
	{
		print_instruction("Error\n");
		exit(1);
	}
}
