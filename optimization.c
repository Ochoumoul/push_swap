#include "push_swap.h"

void    smart_double_rotation(stack *stackA, stack *stackB, t_node *nodeA, t_node *nodeB)
{
    if (nodeB->flag == nodeA->flag)
    {
        while (nodeB->value != (*stackB)->value && nodeA->value != (*stackA)->value)
        {
            if (nodeB->flag == 2)
                reverse_rotate_both(stackA, stackB);
            else
                rotate_both(stackA, stackB);
        }
    }
}

void    top_pair_elements(stack *stackA, stack *stackB, t_node *nodeA, t_node *nodeB)
{
    while (nodeB->value != (*stackB)->value)
    {
        if (nodeB->flag == 2)
            reverse_rotate_el(stackB, "rrb\n"); 
        else
            rotate_el(stackB, "rb\n");
    }
    while (nodeA->value != (*stackA)->value)
    {
        if (nodeA->flag == 2)
            reverse_rotate_el(stackA, "rra\n");
        else
            rotate_el(stackA, "ra\n");
    }
}