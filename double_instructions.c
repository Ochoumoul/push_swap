/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:18 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/01 13:32:11 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// I need to change something about the way i print instruction because the checker is printing instructions that is srewing with the checker result.

void	swap_both(t_stack *stackA, t_stack *stackB)
{
	print_instruction("ss\n");
	swap_el(stackA, "");
	swap_el(stackB, "");
}

void	rotate_both(t_stack *stackA, t_stack *stackB)
{
	print_instruction("rr\n");
	rotate_el(stackA, "");
	rotate_el(stackB, "");
}

void	reverse_rotate_both(t_stack *stackA, t_stack *stackB)
{
	print_instruction("rrr\n");
	reverse_rotate_el(stackA, "");
	reverse_rotate_el(stackB, "");
}
