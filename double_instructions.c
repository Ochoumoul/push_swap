#include "push_swap.h"

void swap_both(stack *stackA, stack *stackB)
{
    print_instruction("ss\n");
    swap_el(stackA, "");
    swap_el(stackB, "");
}

void    rotate_both(stack *stackA, stack *stackB)
{
    print_instruction("rr\n");
    rotate_el(stackA, "");
    rotate_el(stackB, "");
}

void    reverse_rotate_both(stack *stackA, stack *stackB)
{
    print_instruction("rrr\n");
    reverse_rotate_el(stackA, "");
    reverse_rotate_el(stackB, "");
}