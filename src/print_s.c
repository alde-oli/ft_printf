/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:46:52 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/05 09:02:04 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str);

int	print_s(t_flags flags, char *str)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(str);
	if (flags.prec >= 0 && flags.prec < len)
		len = flags.prec;
	if (flags.width > len && flags.sp_side == 0)
		count += print_padding(flags.width - len, ' ');
	if (str)
		count += write(1, str, len);
	else
		count += write(1, "(null)", len);
	if (flags.width > len && flags.sp_side == 1)
		count += print_padding(flags.width - len, ' ');
	return (count);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (6);
	while (str[i])
		i++;
	return (i);
}
