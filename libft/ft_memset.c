/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:18:41 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/09 11:20:51 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)s)[i] = (unsigned char)c;
			i++;
		}
	}
	return (s);
}
