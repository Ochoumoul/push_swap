#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int  max(int value1, int value2)
{
    if (value1 > value2)
        return (value1);
    else
        return (value2);
}

void	print_instruction(char *str)
{
	 int i;

    i = 0;
    while (str[i])
    {
		write(1, &str[i], 1);
        i++;
    }
}