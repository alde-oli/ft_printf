/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:19:12 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 13:04:39 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int nbr);
static int	putnbr(int nbr);

int	print_d(t_flags f, int nbr)
{
	const int	nbr_len = ft_nbrlen(nbr);
	int			total;
	int			count;

	count = 0;
	total = (nbr_len > f.prec) * nbr_len + !(nbr_len > f.prec) * f.prec;
	total += (nbr < 0 || f.is_pls || f.is_sp) - 1 * (nbr == 0 && f.prec == 0);
	if (f.width > total && f.sp_side == 0 && (!f.pad_z || f.prec != -1))
		count += print_padding(f.width - total, ' ');
	count += print_sign(f.is_pls, f.is_sp, nbr < 0);
	if (f.width > total && f.sp_side == 0 && f.pad_z && f.prec == -1)
		count += print_padding(f.width - total, '0');
	while (f.prec > nbr_len)
	{
		count += write(1, "0", 1);
		f.prec--;
	}
	if (!(nbr == 0 && f.prec == 0))
		count += putnbr(nbr);
	if (f.width > total && f.sp_side == 1)
		count += print_padding(f.width - total, ' ');
	return (count);
}

static int	ft_nbrlen(int nbr)
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

static int	putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (write(1, "2147483648", 10));
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 10)
		count += putnbr(nbr / 10);
	count += write(1, &"0123456789"[nbr % 10], 1);
	return (count);
}
