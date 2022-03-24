/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:24 by ochoumou          #+#    #+#             */
/*   Updated: 2022/03/24 11:30:44 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	validate_number(char *str)
{
	int	i;
	int number;
	
	i = 0;
	number = atoi(str);
	if (number > INT_MIN && number < INT_MAX)
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

int	count_numbers(char *str, char sep)
{
	int	i;
	int	words_count;

	i = 0;
	words_count = 0;
	if (str[i] != sep)
	{
		words_count += 1;
		i += 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i - 1] == sep)
			words_count++;
		i++;
	}
	return (words_count);
}

char	**validate_args(int argc, char **args, int *elements)
{
	int		i;
	int		num;
	char	*arg;
	char	**numbers;

	numbers = NULL;
	arg = NULL;
	num = 0;
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
			arg = ft_strjoin(arg, args[i++]);
		num = count_numbers(arg, ' ');
		numbers = ft_split(arg, ' ');
		i = 0;
		while (i < num)
		{
			if (!validate_number(numbers[i]))
				validation_error(1, numbers);
			i++;
		}
	}
	*elements = num;
	return (numbers);
}
