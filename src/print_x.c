/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:35:44 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/05 09:19:41 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_hex_nbrlen(unsigned int nbr);
static int	putnbr_hex(unsigned int nbr, char *base);

int	print_x(t_flags f, unsigned int nbr)
{
	const int	nbr_len = ft_hex_nbrlen(nbr);
	int			count;
	int			total;

	count = 0;
	total = (nbr_len > f.prec) * nbr_len + !(nbr_len > f.prec) * f.prec;
	total += f.is_h * 2 * (nbr != 0) - 1 * (nbr == 0 && f.prec == 0);
	if (f.width > total && f.sp_side == 0 && (!f.pad_z || f.prec != -1))
		count += print_padding(f.width - total, ' ');
	if (f.is_h && nbr != 0 && f.pad_z)
		count += write(1, "0x", 2);
	if (f.width > total && f.sp_side == 0 && f.pad_z && f.prec == -1)
		count += print_padding(f.width - total, '0');
	if (f.is_h && nbr != 0 && !f.pad_z)
		count += write(1, "0x", 2);
	while (f.prec > nbr_len)
	{
		count += write(1, "0", 1);
		f.prec--;
	}
	if (!(nbr == 0 && f.prec == 0))
		count += putnbr_hex(nbr, "0123456789abcdef");
	if (f.width > total && f.sp_side == 1)
		count += print_padding(f.width - total, ' ');
	return (count);
}

int	print_x_up(t_flags f, unsigned int nbr)
{
	const int	nbr_len = ft_hex_nbrlen(nbr);
	int			count;
	int			total;

	count = 0;
	total = (nbr_len > f.prec) * nbr_len + !(nbr_len > f.prec) * f.prec;
	total += f.is_h * 2 * (nbr != 0) - 1 * (nbr == 0 && f.prec == 0);
	if (f.width > total && f.sp_side == 0 && (!f.pad_z || f.prec != -1))
		count += print_padding(f.width - total, ' ');
	if (f.is_h && nbr != 0 && f.pad_z)
		count += write(1, "0X", 2);
	if (f.width > total && f.sp_side == 0 && f.pad_z && f.prec == -1)
		count += print_padding(f.width - total, '0');
	if (f.is_h && nbr != 0 && !f.pad_z)
		count += write(1, "0X", 2);
	while (f.prec > nbr_len)
	{
		count += write(1, "0", 1);
		f.prec--;
	}
	if (!(nbr == 0 && f.prec == 0))
		count += putnbr_hex(nbr, "0123456789ABCDEF");
	if (f.width > total && f.sp_side == 1)
		count += print_padding(f.width - total, ' ');
	return (count);
}

static int	ft_hex_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static int	putnbr_hex(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += putnbr_hex(nbr / 16, base);
	count += write(1, &base[nbr % 16], 1);
	return (count);
}
