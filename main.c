/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:11 by ochoumou          #+#    #+#             */
/*   Updated: 2022/03/24 14:34:26 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	insertion(char **args, t_stack *stack, int args_num)
// {
// 	This function will insert all the numbers on the stack.
// }

int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	a = NULL;
	b = NULL;
	i = 0;
	
	argv = validate_args(argc, argv, &argc);
	i = argc - 1;
	if (argc > 2)
	{
		while (i >= 0)
		{
			if (!find_el(&a, ft_atoi(argv[i])))
				push_el(&a, ft_atoi(argv[i]));
			else
				stack_error(&a);
			i--;
		}
		if (!check_sorted_stack(&a))
		{
			sort_stack(&a, &b);
			sort_all(&a, &b);
		}
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
