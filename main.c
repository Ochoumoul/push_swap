/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:11 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/06 02:50:34 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc >= 2)
	{
		insert_numbers(&a, argv, argc);
		if (!check_sorted_stack(&a))
		{
			if (stack_size(&a) == 3)
				sort_three(&a);
			else if (stack_size(&a) == 5)
				sort_five(&a, &b);
			else
				sort_all(&a, &b);
		}
	}
	return (0);
}
