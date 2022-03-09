#include "push_swap.h"

void    find_list(stack *stack)
{
    t_node *tmp_i;
    t_node *tmp_j;

    tmp_i = (*stack)->next;
    while (tmp_i != NULL)
    {
        tmp_j = *stack;
        while (tmp_j != tmp_i)
        {
            if (tmp_i->value > tmp_j->value)
            {
                tmp_i->length = max(tmp_i->length, tmp_j->length + 1);
                if (tmp_i->length <= tmp_j->length + 1)
                    tmp_i->sub_index = tmp_j->index;
            }
            tmp_j = tmp_j->next;
        }
        tmp_i = tmp_i->next;
    }
}

int    flag_elements(stack *stack)
{
    t_node *tmp_el;
    int i;

    i = 0;
    tmp_el = max_length(stack);
    while (tmp_el->sub_index != -1)
    {
        tmp_el->flag = 1;
        tmp_el = find_index(stack, tmp_el->sub_index);
        i++;
    }
    tmp_el->flag = 1;
    return (i + 1);
}

