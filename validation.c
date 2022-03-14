#include "push_swap.h"

int ft_validate_number(char *str)
{
    int i;

    i = 0;
    if (str[i])
    {
        if ((str[0] == '+' || str[0] == '-') && ft_strlen(str) > 1)
            i += 1;
        while (str[i])
        {
            if (!ft_isdigit(str[i]))
                return (0);
            i++;
        }
        return (1);
    }
    return (0);
}

int	ft_count_numbers(char *str, char sep)
{
	int	i;
	int	words_count;

	i = 0;
	words_count = 0;
	if (str[i] != sep)
	{
		words_count += 1;
		i += 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i - 1] == sep)
			words_count++;
		i++;
	}
	return (words_count);
}

void    free_table(char **table)
{
    int i;

    i = 0;
    while (table[i])
    {
        free(table[i]);
        i++;
    }
}

char    **validate_args(int argc, char **args, int *elements)
{
    int i;
    int num;
    char *arg;
    char **numbers;

    arg = NULL;
    i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            arg = ft_strjoin(arg, args[i]);
            i++;
        }
        num = ft_count_numbers(arg, ' ');
        numbers = ft_split(arg, ' ');
        i = 0;
        while (i < num)
        {
            if (!ft_validate_number(numbers[i]))
            {
                print_instruction("Error inserting the numbers\n");
                free_table(numbers);
                exit(1);
            }
            i++;
        }
    }
    *elements = num;
    return (numbers);
}
