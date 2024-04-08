/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:00:38 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/05 09:02:59 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		is_h;
	int		is_sp;
	int		is_pls;
	int		pad_z;
	int		sp_side;
	int		width;
	int		prec;
}	t_flags;

//main fcts
int	ft_printf(const char *fs, ...);
int	print_arg(const char *fs, int *i, va_list args);
//flags mgmt and utils
int	get_flags(const char *fs, t_flags *flags);
int	print_padding(int width, char c);
int	print_sign(int is_pls, int is_sp, int is_neg);
//arg print fcts
int	print_c(t_flags flags, int c);
int	print_s(t_flags flags, char *s);
int	print_p(t_flags flags, void *p);
int	print_d(t_flags flags, int d);
int	print_u(t_flags flags, unsigned int u);
int	print_x(t_flags flags, unsigned int x);
int	print_x_up(t_flags flags, unsigned int x);
int	print_percent(t_flags flags);

#endif