/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:19:02 by alde-oli          #+#    #+#             */
/*   Updated: 2023/12/31 12:22:23 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_flag(const char *fs, t_flags *flags);
static int	set_width(const char *fs, t_flags *flags);
static int	set_prec(const char *fs, t_flags *flags);

int	get_flags(const char *fs, t_flags *flags)
{
	int	i;

	i = 0;
	*flags = (t_flags){0, 0, 0, 0, 0, 0, -1};
	if (fs[i] == '#' || fs[i] == ' ' || fs[i] == '+'
		|| fs[i] == '0' || fs[i] == '-')
		i += set_flag(fs + i, flags);
	if (fs[i] >= '0' && fs[i] <= '9')
		i += set_width(fs + i, flags);
	if (fs[i] == '.')
		i += set_prec(fs + i, flags);
	return (i);
}

static int	set_flag(const char *fs, t_flags *flags)
{
	int	i;

	i = 0;
	while (fs[i])
	{
		if (fs[i] == '#')
			flags->is_h = 1;
		else if (fs[i] == ' ')
			flags->is_sp = 1;
		else if (fs[i] == '+')
			flags->is_pls = 1;
		else if (fs[i] == '0')
			flags->pad_z = 1;
		else if (fs[i] == '-')
			flags->sp_side = 1;
		else
			break ;
		i++;
	}
	return (i);
}

static int	set_width(const char *fs, t_flags *flags)
{
	int	i;

	i = 0;
	while (fs[i] >= '0' && fs[i] <= '9')
	{
		flags->width = flags->width * 10 + (fs[i] - '0');
		i++;
	}
	return (i);
}

static int	set_prec(const char *fs, t_flags *flags)
{
	int	i;

	i = 1;
	flags->prec = 0;
	while (fs[i] >= '0' && fs[i] <= '9')
	{
		flags->prec = flags->prec * 10 + (fs[i] - '0');
		i++;
	}
	return (i);
}
