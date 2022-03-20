#include "push_swap.h"

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	int i;
	stack a;
	stack b;

	a = NULL;
	b = NULL;
	i = argc - 1;
	// if (argc > 2)
	// {
	// 	while (i > 0)
	// 	{
	// 		if(!find_el(&a, ft_atoi(argv[i])))
	// 			push_el(&a, ft_atoi(argv[i]));
	// 		else
	// 			stack_error(&a);
	// 		i--;
	// 	}
	// 	if (!check_sorted_stack(&a))	
	// 	{
	// 		sort_stack(&a, &b);
	// 		while (1);
	// 		sort_all(&a, &b);
	// 	}
	// }
	// else
	// 	printf("Invalid arguments\n");
	push_el(&a, 4);
	push_el(&a, 5);
	push_el(&a, 6);
	push_el(&b, 1);
	push_el(&b, 3);
	push_stack(&a, &b, "pb");
	// rotate_el(&b, "rb");
	reverse_rotate_el(&b, "rrb");
	print_stack(&b);
	while (1);
	return (0);
}