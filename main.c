#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	int t;
	stack a;
	stack b;
	t_node *tmp;

	a = NULL;
	b = NULL;
	i = argc - 1;
	if (argc > 2)
	{
		while (i > 0)
		{
			if(!find_el(&a, ft_atoi(argv[i])))
				push_el(&a, ft_atoi(argv[i]));
			else
				stack_error(&a);
			i--;
		}
		sort_stack(&a, &b);
		top_pair_elements(&a, &b);
		// print_stack(&a);
		// find_best_element(&a, &b);
		// print_stack(&a);
		// tmp = best_element(&b);
		// rotate_el(&a);
		// rotate_el(&a);
		// rotate_el(&a);
		// push_stack(&b, &a);
		// pair_elements(&a, &b);
		// find_best_element(&a, &b);
		// tmp = best_element(&b);
		// printf("The best: %d [%d]\n", tmp->value, tmp->index);
		// reverse_rotate_el(&b);
		// push_stack(&b, &a);
		// print_stack(&a);
		// print_stack(&b);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}