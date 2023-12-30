/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:27:21 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/30 19:45:42 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_nbrlen(unsigned int nbr);
static int	putnbr_unsigned(unsigned int nbr);

int	print_u(t_flags flags, unsigned int nbr)
{
	const int	nbr_len = ft_unsigned_nbrlen(nbr);
	int			count;
	int			total_len;

	count = 0;
	if (nbr_len > flags.prec)
		total_len = nbr_len;
	else
		total_len = flags.prec;
	if (flags.width > total_len && flags.sp_side == 0)
		count += print_padding(flags.width - total_len,
				'0' * flags.pad_z + ' ' * !flags.pad_z);
	while (flags.prec > nbr_len)
	{
		count += write(1, "0", 1);
		flags.prec--;
	}
	count += putnbr_unsigned(nbr);
	if (flags.width > total_len && flags.sp_side == 1)
		count += print_padding(flags.width - total_len, ' ');
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
