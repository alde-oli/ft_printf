/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:33 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/10 14:39:05 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (s[i] == c && s[i + 1] != c && s[i + 1])
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
	dest = ft_calloc((j + 1), sizeof(char));
	if (!dest)
		return (NULL);
	j = 0;
	while (src[*i] && src[*i] != c)
	{
		dest[j] = src[*i];
		j++;
		(*i)++;
	}
	return (dest);
}

static int	ft_destclear(char ***dest, int j)
{
	if (!(*dest)[j])
	{
		while (j > 0)
		{
			free((*dest)[j]);
			j--;
		}
		return (1);
	}
	return (0);
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
	dest = ft_calloc((s_nbr + 1), sizeof(char *));
	if (!dest)
		return (NULL);
	while (j < s_nbr)
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		dest[j] = ft_strcdup(s, &i, c);
		if (ft_destclear(&dest, j))
			return (NULL);
		j++;
	}
	return (dest);
}
