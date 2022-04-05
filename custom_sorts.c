#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	t_node	*tmp;

	tmp = *stack;
	if (tmp->value < tmp->next->next->value)
	{
		if (tmp->next->value < tmp->value)
			swap_el(stack, "sa\n");
		else if (tmp->next->value > tmp->next->next->value)
		{
            swap_el(stack, "sa\n");
            rotate_el(stack, "ra\n");
        }
	}
	else
	{
		if (tmp->value > tmp->next->value)
		{
			if (tmp->next->value < tmp->next->next->value)
				 rotate_el(stack, "ra\n");
			else
			{
                swap_el(stack, "sa\n");
                reverse_rotate_el(stack, "rra\n");
            }
		}
		else
			reverse_rotate_el(stack, "rra\n");
	}
}

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int i;

    i = 2;
    while (i > 0)
    {
        top_min_element(stack_a);
        push_stack(stack_a, stack_b, "pb\n");
        i--;
    }
    sort_three(stack_a);
    push_stack(stack_b, stack_a, "pa\n");
    push_stack(stack_b, stack_a, "pa\n");
}