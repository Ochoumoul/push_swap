#include "push_swap.h"
#include <string.h>
#include <stdio.h>

int	check_sorted_stack(t_stack *stack)
{
	t_node	*tmp;

	if (*stack)
	{
		tmp = *stack;
		while (tmp->next != NULL)
		{
			if (tmp->value < tmp->next->value)
				tmp = tmp->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

void    apply_single(char *inst, t_stack *stackA, t_stack *stackB)
{
    if (strcmp(inst, "pa\n") == 0)
        push_stack(stackB, stackA, "");
    else if (strcmp(inst, "pb\n") == 0)
        push_stack(stackA, stackB, "");
    else if (strcmp(inst, "ra\n") == 0)
        rotate_el(stackA, "");
    else if (strcmp(inst, "rb\n") == 0)
        rotate_el(stackB, "");
    else if (strcmp(inst, "rra\n") == 0)
        reverse_rotate_el(stackA, "");
    else if (strcmp(inst, "rrb\n") == 0)
        reverse_rotate_el(stackB, "");
    else if (strcmp(inst, "sa\n") == 0)
        swap_el(stackB, "");
    else if (strcmp(inst, "sb\n") == 0)
        swap_el(stackB, "");
}

void    apply_double(char *inst, t_stack *stackA, t_stack *stackB)
{
    if (strcmp(inst, "ss\n") == 0)
        swap_both(stackB, stackA);
    else if (strcmp(inst, "rr\n") == 0)
        rotate_both(stackA, stackB);
    else if (strcmp(inst, "rrr\n") == 0)
        reverse_rotate_both(stackA, stackB);
}

void    checker(t_stack *stackA, t_stack *stackB)
{
    if (stack_size(stackB) == 0 && check_sorted_stack(stackA))
        print_instruction("OK\n");
    else
        print_instruction("KO\n");
}

int main(int argc,char **argv)
{
    char *str;
    t_stack stack_a;
    t_stack stack_b;

    if (argc > 1)
    {
        insert_numbers(&stack_a, argv, argc);
        while ((str = get_next_line(0)) != NULL)
        {
            if (!strcmp(str, "ss\n") || !strcmp(str, "rr\n") || !strcmp(str, "rrr\n"))
                apply_double(str, &stack_a, &stack_b);
            else if (!strcmp(str, "pa\n") || !strcmp(str, "pb\n") || !strcmp(str, "rrb\n") || !strcmp(str, "rra\n")
            || !strcmp(str, "ra\n") || !strcmp(str, "rb\n")\
            || !strcmp(str, "sa\n") || !strcmp(str, "sb\n"))
                apply_single(str, &stack_a, &stack_b);
            else
                validation_error(2, NULL);
        }
        checker(&stack_a, &stack_b);
    }
    else
        printf("Invalid number of agruments\n");
    return (0);
}