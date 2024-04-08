/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:00:25 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/30 18:10:13 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen_hex(unsigned long long nbr);
static int	putnbr_hex(unsigned long long nbr);

int	print_p(t_flags flags, void *ptr)
{
	const unsigned long long	addr = (unsigned long long)ptr;
	const int					addr_len = ft_nbrlen_hex(addr) + 2;
	int							count;

	count = 0;
	if (flags.width > addr_len && flags.sp_side == 0)
		count += print_padding(flags.width - addr_len, ' ');
	count += write(1, "0x", 2);
	count += putnbr_hex(addr);
	if (flags.width > addr_len && flags.sp_side == 1)
		count += print_padding(flags.width - addr_len, ' ');
	return (count);
}

static int	ft_nbrlen_hex(unsigned long long nbr)
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

static int	putnbr_hex(unsigned long long nbr)
{
	const char	*base = "0123456789abcdef";
	int			count;

	count = 0;
	if (nbr >= 16)
		count += putnbr_hex(nbr / 16);
	count += write(1, &base[nbr % 16], 1);
	return (count);
}
