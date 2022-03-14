#include "push_swap.h"

static int	ft_count_words(char *str, char sep)
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

static char	**ft_free_dst(char **dst, int i)
{
	while (i--)
		free(dst[i]);
	free(dst);
	return (dst);
}

static char	**ft_return_value(char **words, int j)
{
	words[j] = NULL;
	return (words);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**words;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	words = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	while (s[i] != '\0' && j < ft_count_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		words[j] = ft_substr(s, start, (i - start));
		if (!words[j])
			return (ft_free_dst(words, j));
		j++;
	}
	return (ft_return_value(words, j));
}
