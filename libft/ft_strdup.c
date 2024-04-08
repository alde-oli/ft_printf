/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:41:21 by alde-oli          #+#    #+#             */
/*   Updated: 2023/10/09 11:41:45 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = ft_calloc((ft_strlen(src) + 1), sizeof(char));
	ft_strlcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}
