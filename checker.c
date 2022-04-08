/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 00:33:17 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/08 21:53:53 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_single(char *inst, t_stack *stackA, t_stack *stackB)
{
	if (ft_strcmp(inst, "pa\n") == 0)
		push_stack(stackB, stackA, "");
	else if (ft_strcmp(inst, "pb\n") == 0)
		push_stack(stackA, stackB, "");
	else if (ft_strcmp(inst, "ra\n") == 0)
		rotate_el(stackA, "");
	else if (ft_strcmp(inst, "rb\n") == 0)
		rotate_el(stackB, "");
	else if (ft_strcmp(inst, "rra\n") == 0)
		reverse_rotate_el(stackA, "");
	else if (ft_strcmp(inst, "rrb\n") == 0)
		reverse_rotate_el(stackB, "");
	else if (ft_strcmp(inst, "sa\n") == 0)
		swap_el(stackA, "");
	else if (ft_strcmp(inst, "sb\n") == 0)
		swap_el(stackB, "");
}

void	apply_double(char *inst, t_stack *stackA, t_stack *stackB)
{
	if (ft_strcmp(inst, "ss\n") == 0)
		swap_both(stackB, stackA, "");
	else if (ft_strcmp(inst, "rr\n") == 0)
		rotate_both(stackA, stackB, "");
	else if (ft_strcmp(inst, "rrr\n") == 0)
		reverse_rotate_both(stackA, stackB, "");
}

void	checker(t_stack *stackA, t_stack *stackB)
{
	if (stack_size(stackB) == 0 && check_sorted_stack(stackA))
		print_instruction("OK\n");
	else
		print_instruction("KO\n");
}

int	check_intruction(char *str)
{
	if (!ft_strcmp(str, "ss\n") || !ft_strcmp(str, "rr\n") \
	|| !ft_strcmp(str, "rrr\n"))
		return (1);
	else if (!ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pb\n") \
			|| !ft_strcmp(str, "rrb\n") || !ft_strcmp(str, "rra\n") \
			|| !ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n") \
			|| !ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n"))
		return (2);
	else
		return (3);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc > 1)
	{
		insert_numbers(&stack_a, argv, argc);
		str = get_next_line(0);
		while (str != NULL)
		{
			if (check_intruction(str) == 1)
				apply_double(str, &stack_a, &stack_b);
			else if (check_intruction(str) == 2)
				apply_single(str, &stack_a, &stack_b);
			else
				validation_error(2, NULL);
			str = get_next_line(0);
		}
		checker(&stack_a, &stack_b);
	}
	return (0);
}
