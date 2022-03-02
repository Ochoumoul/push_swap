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
	i = 1;
	if (argc > 2)
	{
		while (argv[i])
		{
			if(!find_el(&a, ft_atoi(argv[i])))
				push_el(&a, ft_atoi(argv[i]));
			else
				stack_error(&a);
			i++;
		}
		sort_stack(&a, &b);
		// reverse_rotate_el(&a);
		pair_elements(&a, &b);
		// rotate_el(&a);
		// rotate_el(&a);
		// rotate_el(&a);
		// push_stack(&b, &a);
		// reverse_rotate_el(&a);
		// push_stack(&b, &a);
		// top_min_element(&a);
		print_stack(&a);
		print_stack(&b);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}