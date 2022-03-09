#include "push_swap.h"

int stack_size(stack *stack)
{
    int size;
    t_node *tmp;

    size = 0;
    tmp = *stack;
    while (tmp != NULL)
    {
        size += 1;
        tmp = tmp->next;
    }
    return (size);
}

t_node *find_index(stack *stack, int index)
{
    t_node *tmp;

    tmp = *stack;
    while (tmp != NULL)
    {
        if (tmp->index == index)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void    index_stack(stack *stack)
{
    int i;
    t_node *tmp;

    tmp = *stack;
    i = 0;
    while (tmp != NULL)
    {
        tmp->index = i++;
        tmp = tmp->next;
    }
}