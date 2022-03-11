#include "push_swap.h"

void    top_min_element(stack *stackA)
{
    int     list_half;
    t_node  *min;

	min = min_number(stackA);
    list_half = stack_size(stackA) / 2;
    while ((*stackA)->value != min->value)
    {
        if (min->index > list_half)
            reverse_rotate_el(stackA, "rra\n");
        else
            rotate_el(stackA, "ra\n");
    }
}

int check_sorted_stack(stack *stack)
{
    t_node *tmp;

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
    else
        return (0);
}

int check_flags(stack *stack)
{
    t_node *tmp;

    tmp = *stack;
    while (tmp != NULL)
    {
        if (tmp->flag == 0)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    sort_stack(stack *stackA, stack *stackB)
{
    int     size;
    t_node *tmp;
    
    index_stack(stackA);
	find_list(stackA);
    flag_elements(stackA);
    size = stack_size(stackA);
    while (size)
    {
        // if (!check_flags(stackA))
        //     return ;
        if ((*stackA)->flag == 1)
            rotate_el(stackA, "ra\n");
        else 
            push_stack(stackA, stackB, "pb\n");
        size--;
    }
}

void    sort_all(stack *stackA, stack *stackB)
{
    t_node *tmp_b;
    t_node *tmp_a;

    while (stack_size(stackB) != 0)
    {
        index_stack(stackA);
        index_stack(stackB);
        pair_elements(stackA, stackB);
        search_best_element(stackA, stackB);
        flag_best_element(stackA, stackB);
        tmp_b = best_element(stackB);
        tmp_a = find_index(stackA, tmp_b->sub_index);
        smart_double_rotation(stackA, stackB, tmp_a, tmp_b);
        top_pair_elements(stackA, stackB, tmp_a, tmp_b);
        push_stack(stackB, stackA, "pa\n");
    }
    top_min_element(stackA);
}
