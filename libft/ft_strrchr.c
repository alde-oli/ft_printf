/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:29:07 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/10 09:44:38 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*found;

	if (!s)
		return (NULL);
	i = 0;
	found = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			found = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		found = (char *)&s[i];
	if (found)
		return (found);
	return (NULL);
}
