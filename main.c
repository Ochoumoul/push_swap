#include "utils.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	stack a;
	stack b;

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
		if (!check_sorted_stack(&a))	
		{
			sort_stack(&a, &b);
			sort_all(&a, &b);
		}
		// print_stack(&a);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}