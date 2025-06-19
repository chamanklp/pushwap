#include "utils.h"

long	ft_atol(char *str)
{
	int	i;
	long	signe;
	long	total;

	if(ft_strlen(str) > 11)
		return(+2147483648);
	signe = 1;
	i = 0;
	total = 0;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            signe = -1;
        i++;
    }
	while (str[i] > 47 && str[i] < 58)
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (total * signe);
}
static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}