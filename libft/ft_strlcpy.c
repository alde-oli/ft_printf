/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:24:42 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/09 11:25:33 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (0);
	i = 0;
	while (i + 1 < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (len > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
