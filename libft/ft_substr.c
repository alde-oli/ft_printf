/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:41:59 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/10 13:58:20 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (s_len < start || s_len == 0 || len == 0)
		len = 0;
	else if (s_len < start + len)
		len = s_len - start;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len && start + i < s_len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
