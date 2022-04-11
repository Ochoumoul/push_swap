/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:24 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/11 03:03:46 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**join_tables(char **table, char **table2)
{
	int		size;
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	size = count_elements(table) + count_elements(table2);
	str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	while (table && table[j])
		str[i++] = table[j++];
	j = 0;
	while (table2 && table2[j])
		str[i++] = table2[j++];
	free(table);
	str[i] = NULL;
	return (str);
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

void	ft_validate_table(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (table[i])
	{
		if (validate_number(table[i]))
			i++;
		else
			ft_error();
	}
}

char	**parse_input(int argc, char **args, int *elements)
{
	int		i;
	char	**table;
	char	**split;

	i = 1;
	table = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (ft_strlen(args[i]) > 0 && (count_numbers(args[i], ' ') > 0))
			{
				split = ft_split(args[i], ' ');
				table = join_tables(table, split);
				free(split);
				i++;
			}
			else
				validation_error(1, table);
		}
		ft_validate_table(table);
		*elements = count_elements(table);
	}
	return (table);
}
