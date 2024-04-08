/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:02:08 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/05 09:02:31 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width > 1 && flags.sp_side == 0)
		count += print_padding(flags.width - 1, ' ');
	count += write(1, "%", 1);
	if (flags.width > 1 && flags.sp_side == 1)
		count += print_padding(flags.width - 1, ' ');
	return (count);
}
