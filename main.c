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
				push_el(&a, ft_atoi(argv[i]), i);
			else
				stack_error(&a);
			i++;
		}
		sort_stack(&a, &b);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}