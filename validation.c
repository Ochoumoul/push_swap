#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int validate(char *str)
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

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	dstlen;

	i = 0;
	dstlen = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[dstlen + i] = src[i];
		i++;
	}
	dest[dstlen + i] = '\0';
	return (dest);
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



char	*ft_strjoin(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	char	*str;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * ((s1len + s2len) + 1));
	if (!str)
		return (NULL);
    str[0] = '\0';
	if (s1)
        ft_strcat(str, s1);
		ft_strcat(str, " ");
	if (s2)
		ft_strcat(str, s2);
    free(s1);
	return (str);
}

void    ft_free_table(char **table)
{
    int i;

    i = 0;
    while (table[i])
    {
        free(table[i]);
        i++;
    }
}

int main(int argc,char **argv)
{
    int i;
    int j;
    int k;
    char *args;
    char **numbers;
    int num;


    args = NULL;
    i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            args = ft_strjoin(args, argv[i]);
            i++;
        }
        num = ft_count_numbers(args, ' ');
        numbers = ft_split(args, ' ');
        i = 0;
        while (i < num)
        {
            if (!validate(numbers[i]))
            {
                printf("Error inserting the numbers\n");
                exit(1);
            }
            i++;
        }
    }
    while (1);
    return (0);
}