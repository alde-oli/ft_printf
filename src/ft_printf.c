/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:49:10 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/30 17:37:26 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fs, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!fs)
		return (-1);
	va_start(args, fs);
	while (fs[i] && i >= 0)
	{
		if (fs[i] == '%')
		{
			i++;
			count += print_arg(fs, &i, args);
		}
		else
			count += write(1, &fs[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
