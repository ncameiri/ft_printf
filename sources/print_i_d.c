/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:40 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:42 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	arg_mng_int(t_argdata *arg_data, t_int_ctrl *i_ct)
{
	arg_data->flags_do = 0;
	if (arg_data->zero && arg_data->menos)
		arg_data->zero = 0;
	if (arg_data->zero && arg_data->width < 0 && !arg_data->precision_do)
		arg_data->flags_do = 1;
	if (arg_data->zero && !arg_data->precision_do && !arg_data->flags_do)
	{
		i_ct->zer_sp = 1;
		arg_data->precision = arg_data->width;
		arg_data->precision_do = 1;
	}
}

void	arg_mng_int2(t_argdata *arg_data, t_int_ctrl *i_ct,
		t_input *i_s)
{
	if (i_ct->zer_sp && i_ct->neg)
		arg_data->precision -= 1;
	if (arg_data->width < 0)
	{
		arg_data->width = (-arg_data->width);
		arg_data->menos = 1;
	}
	if ((arg_data->width) <= (arg_data->precision) ||
			((arg_data->width) <= (i_ct->digits + i_ct->neg) && i_ct->i != 0))
		arg_data->width_do = 0;
	if (arg_data->precision_do && arg_data->precision > i_ct->digits)
		arg_data->width -= (arg_data->precision - i_ct->digits);
	if (arg_data->width_do)
	{
		arg_data->width -= ((i_ct->digits) + i_ct->neg);
		if (arg_data->menos == 0)
			white_space(i_s, arg_data);
	}
}

void	init_i_str(va_list args, t_int_ctrl *i_ct, t_argdata *arg_data)
{
	i_ct->digits = 0;
	i_ct->neg = 0;
	i_ct->zer_sp = 0;
	i_ct->i = va_arg(args, int);
	i_ct->a = i_ct->i;
	arg_mng_int(arg_data, i_ct);
}

void	id_operat(t_input *i_s, t_int_ctrl *i_ct)
{
	if (i_ct->a == -2147483648)
	{
		i_s->f_rt += 11;
		i_ct->digits = 11;
	}
	else if (i_ct->a < 0)
	{
		i_s->f_rt += 1;
		i_ct->i *= -1;
		i_ct->a = i_ct->i;
		i_ct->neg = 1;
	}
	while (i_ct->a >= 0 && i_ct->a != -2147483648)
	{
		i_ct->a /= 10;
		i_s->f_rt += 1;
		i_ct->digits += 1;
		if (i_ct->a == 0)
			break ;
	}
}

void	print_int(va_list args, t_input *i_s,
		t_argdata *arg_data)
{
	t_int_ctrl	i_ct;

	init_i_str(args, &i_ct, arg_data);
	id_operat(i_s, &i_ct);
	arg_mng_int2(arg_data, &i_ct, i_s);
	if (i_ct.neg)
		write(1, "-", 1);
	if (arg_data->precision_do)
		zer_prec((arg_data->precision - i_ct.digits), i_s);
	if (arg_data->precision == 0 && i_ct.i == 0 && arg_data->precision_do)
	{
		if (!arg_data->width_do)
			i_s->f_rt -= 1;
		else
			write(1, " ", 1);
	}
	else
		ft_putnbr_fd(i_ct.i, 1);
	if ((arg_data->menos && arg_data->width_do))
		white_space(i_s, arg_data);
}
