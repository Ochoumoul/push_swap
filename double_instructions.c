/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:18 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/04 00:00:13 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *stackA, t_stack *stackB, char *inst)
{
	swap_el(stackA, "");
	swap_el(stackB, "");
	print_instruction(inst);
}

void	rotate_both(t_stack *stackA, t_stack *stackB, char *inst)
{
	rotate_el(stackA, "");
	rotate_el(stackB, "");
	print_instruction(inst);
}

void	reverse_rotate_both(t_stack *stackA, t_stack *stackB, char *inst)
{
	reverse_rotate_el(stackA, "");
	reverse_rotate_el(stackB, "");
	print_instruction(inst);
}
