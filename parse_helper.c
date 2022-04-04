/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:18:06 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/04 02:56:54 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	print_instruction("Error\n");
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	validate_number(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = ft_atoi(str);
	if (number >= INT_MIN && number <= INT_MAX)
	{
		if (str[i])
		{
			if ((str[0] == '+' || str[0] == '-') && ft_strlen(str) > 1)
				i += 1;
			while (str[i])
			{
				if (!ft_isdigit(str[i]))
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}

int	count_elements(char **table)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (table == NULL)
		return (count);
	while (table[i++])
		count++;
	return (count);
}
