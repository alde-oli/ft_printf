/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:44:24 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/30 17:45:42 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_flags flags, int c)
{
	int	count;

	count = 0;
	if (flags.width > 1 && flags.sp_side == 0)
		count += print_padding(flags.width - 1, ' ');
	count += write(1, &c, 1);
	if (flags.width > 1 && flags.sp_side == 1)
		count += print_padding(flags.width - count, ' ');

	return (count);
}
