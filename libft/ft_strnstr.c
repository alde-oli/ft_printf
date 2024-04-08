/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:38:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/10 12:04:09 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*n)
		return ((char *)h);
	i = 0;
	while (i < len && h[i])
	{
		j = 0;
		while (h[i + j] == n[j] && i + j < len)
		{
			if (!n[j + 1])
				return ((char *)&(h[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
