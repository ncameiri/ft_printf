/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:04 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:06 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_conv(t_input *i_s, t_argdata *arg_data)
{
	if (arg_data->zero && !arg_data->menos)
		arg_data->flags_do = 1;
	if (arg_data->width > 0)
		arg_data->width -= 1;
	if (arg_data->width < 0)
		arg_data->width += 1;
	if (arg_data->width_do && !arg_data->menos)
	{
		if (arg_data->flags_do)
			zer_prec(arg_data->width, i_s);
		else
			white_space(i_s, arg_data);
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		if (arg_data->flags_do)
			zer_prec(arg_data->width, i_s);
		else
			white_space(i_s, arg_data);
	}
	i_s->f_rt += 1;
}

int		mng_specifier(va_list args, t_input *i_s, t_argdata *arg_data)
{
	if (i_s->in[i_s->ind] == 'c')
		printchar(args, i_s, arg_data);
	else if (i_s->in[i_s->ind] == 's')
		printstring(args, i_s, arg_data);
	else if (i_s->in[i_s->ind] == 'd')
		print_int(args, i_s, arg_data);
	else if (i_s->in[i_s->ind] == 'i')
		print_int(args, i_s, arg_data);
	else if (i_s->in[i_s->ind] == 'x')
		print_hexa(args, i_s, arg_data, 0);
	else if (i_s->in[i_s->ind] == 'X')
		print_hexa(args, i_s, arg_data, 1);
	else if (i_s->in[i_s->ind] == 'p')
		print_point(args, i_s, arg_data);
	else if (i_s->in[i_s->ind] == 'u')
		print_uint(args, i_s, arg_data);
	else if (i_s->in[i_s->ind] == '%')
		percent_conv(i_s, arg_data);
	i_s->ind++;
	return (0);
}
