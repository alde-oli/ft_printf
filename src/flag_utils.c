/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:23:24 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/30 17:37:55 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding(int width, char c)
{
	int	i;

	i = 0;
	while (i < width)
		i += write(1, &c, 1);
	return (i);
}

int	print_sign(int is_pls, int is_sp, int is_neg)
{
	if (is_neg)
		return (write(1, "-", 1));
	else if (is_pls)
		return (write(1, "+", 1));
	else if (is_sp)
		return (write(1, " ", 1));
	return (0);
}
