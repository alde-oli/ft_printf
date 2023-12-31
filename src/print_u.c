/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:27:21 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 13:06:09 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_nbrlen(unsigned int nbr);
static int	putnbr_unsigned(unsigned int nbr);

int	print_u(t_flags f, unsigned int nbr)
{
	const int	nbr_len = ft_unsigned_nbrlen(nbr);
	int			count;
	int			total;

	count = 0;
	total = (nbr_len > f.prec) * nbr_len + !(nbr_len > f.prec) * f.prec;
	total -= 1 * (nbr == 0 && f.prec == 0);
	if (f.width > total && f.sp_side == 0 && (!f.pad_z || f.prec != -1))
		count += print_padding(f.width - total, ' ');
	if (f.width > total && f.sp_side == 0 && f.pad_z && f.prec == -1)
		count += print_padding(f.width - total, '0');
	while (f.prec > nbr_len)
	{
		count += write(1, "0", 1);
		f.prec--;
	}
	if (!(nbr == 0 && f.prec == 0))
		count += putnbr_unsigned(nbr);
	if (f.width > total && f.sp_side == 1)
		count += print_padding(f.width - total, ' ');
	return (count);
}

static int	ft_unsigned_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static int	putnbr_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += putnbr_unsigned(nbr / 10);
	count += write(1, &"0123456789"[nbr % 10], 1);
	return (count);
}
