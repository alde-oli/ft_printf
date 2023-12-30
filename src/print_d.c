/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:19:12 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/30 19:45:16 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int nbr);
static int	putnbr(int nbr);

int	print_d(t_flags flags, int nbr)
{
	const int	nbr_len = ft_nbrlen(nbr);
	int			total_len;
	int			count;

	count = 0;
	if (nbr_len > flags.prec)
		total_len = nbr_len;
	else
		total_len = flags.prec;
	total_len += (nbr < 0 || flags.is_pls || flags.is_sp);
	if (flags.width > total_len && flags.sp_side == 0)
		count += print_padding(flags.width - total_len,
				'0' * flags.pad_z + ' ' * !flags.pad_z);
	count += print_sign(flags.is_pls, flags.is_sp, nbr < 0);
	while (flags.prec > nbr_len)
	{
		count += write(1, "0", 1);
		flags.prec--;
	}
	count += putnbr(nbr);
	if (flags.width > total_len && flags.sp_side == 1)
		count += print_padding(flags.width - total_len, ' ');
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
