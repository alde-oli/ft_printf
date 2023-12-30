/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:35:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/30 19:46:04 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_nbrlen(unsigned int nbr);
static int	putnbr_hex(unsigned int nbr, char *base);

int	print_x(t_flags flags, unsigned int nbr)
{
	const int	nbr_len = ft_hex_nbrlen(nbr);
	int			count;
	int			total_len;

	count = 0;
	if (nbr_len > flags.prec)
		total_len = nbr_len;
	else
		total_len = flags.prec;
	total_len += flags.is_h * 2;
	if (flags.width > total_len && flags.sp_side == 0)
		count += print_padding(flags.width - total_len,
				'0' * flags.pad_z + ' ' * !flags.pad_z);
	if (flags.is_h && nbr != 0)
		count += write(1, "0x", 2);
	while (flags.prec > nbr_len)
	{
		count += write(1, "0", 1);
		flags.prec--;
	}
	count += putnbr_hex(nbr, "0123456789abcdef");
	if (flags.width > total_len && flags.sp_side == 1)
		count += print_padding(flags.width - total_len, ' ');
	return (count);
}

int	print_x_up(t_flags flags, unsigned int nbr)
{
	const int	nbr_len = ft_hex_nbrlen(nbr);
	int			count;
	int			total_len;

	count = 0;
	if (nbr_len > flags.prec)
		total_len = nbr_len;
	else
		total_len = flags.prec;
	total_len += flags.is_h * 2;
	if (flags.width > total_len && flags.sp_side == 0)
		count += print_padding(flags.width - total_len,
				'0' * flags.pad_z + ' ' * !flags.pad_z);
	if (flags.is_h && nbr != 0)
		count += write(1, "0X", 2);
	while (flags.prec > nbr_len)
	{
		count += write(1, "0", 1);
		flags.prec--;
	}
	count += putnbr_hex(nbr, "0123456789ABCDEF");
	if (flags.width > total_len && flags.sp_side == 1)
		count += print_padding(flags.width - total_len, ' ');
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
