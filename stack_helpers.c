#include "push_swap.h"

t_node	*min_number(stack *stack)
{
    int     min;
    t_node *tmp_node;
    t_node *tmp;

	tmp_node = *stack;
    min = tmp_node->value;
	while (tmp_node != NULL)
	{
		if (min >= tmp_node->value)
        {
            tmp = tmp_node;
            min = tmp_node->value;
        }
		tmp_node = tmp_node->next;
	}
	return (tmp);
}

t_node	*max_length(stack *stack)
{
    int     max;
    t_node *tmp_node;
    t_node *tmp;

	tmp_node = *stack;
    max = tmp_node->length;
	while (tmp_node != NULL)
	{
		if (max < tmp_node->length)
        {
            tmp = tmp_node;
            max = tmp_node->length;
        }
		tmp_node = tmp_node->next;
	}
	return (tmp);
}

t_node	*best_element(stack *stack)
{
    int     min;
    t_node *tmp_node;
    t_node *tmp;

	tmp_node = *stack;
    min = tmp_node->length;
    tmp = tmp_node;
	while (tmp_node != NULL)
	{
		if (min >= tmp_node->length)
        {
            tmp = tmp_node;
            min = tmp_node->length;
        }
		tmp_node = tmp_node->next;
	}
	return (tmp);
}