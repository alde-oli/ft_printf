#include "../libft.h"

static int	ft_strnbr(char const *s, char c)
{
	int	s_nbr;
	int	i;

	s_nbr = 0;
	i = 0;
	if (s[i] != c)
		s_nbr++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			s_nbr++;
		i++;
	}
	return (s_nbr);
}

static char	*ft_strcdup(char const *src, int *i, char c)
{
	int		j;
	char	*dest;

	j = 0;
	while (src[*i + j] && src[*i + j] != c)
		j++;
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (src[*i] && src[*i] != c)
	{
		dest[j] = src[*i];
		j++;
		(*i)++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		s_nbr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	s_nbr = ft_strnbr(s, c);
	dest = (char **)malloc(sizeof(char *) * (s_nbr + 1));
	if (!dest)
		return (NULL);
	while (j < s_nbr)
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break;
		dest[j] = ft_strcdup(s, &i, c);
		if (!dest[j])
		{
			while (j > 0)
			{
				free(dest[j - 1]);
				j--;
			}
			free(dest);
			return (NULL);
		}
		j++;
	}
	dest[j] = NULL;
	return (dest);
}