/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:04:24 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/05 09:01:37 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(const char *fs, int *i, va_list args)
{
	t_flags	flags;

	*i += get_flags(fs + *i, &flags);
	if (fs[*i] == 'c')
		return (print_c(flags, va_arg(args, int)));
	else if (fs[*i] == 's')
		return (print_s(flags, va_arg(args, char *)));
	else if (fs[*i] == 'p')
		return (print_p(flags, va_arg(args, void *)));
	else if (fs[*i] == 'd' || fs[*i] == 'i')
		return (print_d(flags, va_arg(args, int)));
	else if (fs[*i] == 'u')
		return (print_u(flags, va_arg(args, unsigned int)));
	else if (fs[*i] == 'x')
		return (print_x(flags, va_arg(args, unsigned int)));
	else if (fs[*i] == 'X')
		return (print_x_up(flags, va_arg(args, unsigned int)));
	else if (fs[*i] == '%')
		return (print_percent(flags));
	else
		return (0);
}
