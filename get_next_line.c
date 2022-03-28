#include "push_swap.h"

char *ft_strdup(char *str)
{
    char *new;
    int i;

    i = 0;
    new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!new)
        return (NULL);
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *get_next_line(int fd)
{
    if (fd < 0)
        return (NULL);
    char buff[1];
    char line[1000000];
    line[0] = 0;
    int i = 0;
    int n;
    while ((n = read(fd, buff, 1)) && n > 0)
    {
        line[i++] = buff[0];
        line[i] = '\0';
        if (buff[0] == '\n')
            return (ft_strdup(line));
    }
    if (!line[0])
        return (NULL);
    return (ft_strdup(line));
}