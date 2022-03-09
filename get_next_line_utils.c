#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int i;
	char *str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0' && (char)c != '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*new;

	i = 0;
	size = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		len = 0;
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc((sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
static	char	*ft_strcat(char *dest, char const *src)
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
*/

char    *ft_strjoin(char *s1, char *s2)
{
    size_t    len;
    char    *join;
    size_t    i;
    size_t    j;
    size_t    k;

	if (!s1)
		s1 = ft_strdup("");
    len = ft_strlen(s1) + ft_strlen(s2);
    join = (char *)malloc(sizeof(char) * (len + 1));
    if (!join)
        return (NULL);
    i = 0;
    j = 0;
    k = 0;
    while (s1[k])
        join[i++] = s1[k++];
    k = 0;
    while (s2[k])
        join[i++] = s2[k++];
    join[i] = '\0';
    free(s1);
    return (join);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc((sizeof(char) * (s1len + s2len + 1)));
	if (!str)
		return (NULL);
	if (s1)
		ft_strcat(str, s1);
	if (s2)
		ft_strcat(str, s2);
	return (str);
}
*/
