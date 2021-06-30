/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:59 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:31:00 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	arg_mng_uint(t_argdata *arg_data, t_uint_ctrl *ui_ct)
{
	arg_data->flags_do = 0;
	if (arg_data->zero && arg_data->menos)
		arg_data->zero = 0;
	if (arg_data->zero && arg_data->width < 0 && !arg_data->precision_do)
		arg_data->flags_do = 1;
	if (arg_data->zero && !arg_data->precision_do && !arg_data->flags_do)
	{
		ui_ct->zer_sp = 1;
		arg_data->precision = arg_data->width;
		arg_data->precision_do = 1;
	}
}

void	arg_mng_uint2(t_argdata *arg_data, t_uint_ctrl *ui_ct, t_input *i_s)
{
	if (arg_data->width < 0)
	{
		arg_data->width = (-arg_data->width);
		arg_data->menos = 1;
	}
	if ((arg_data->width) <= (arg_data->precision) || ((arg_data->width)
			<= (ui_ct->digits + ui_ct->neg) && ui_ct->i != 0))
		arg_data->width_do = 0;
	if (arg_data->precision_do && arg_data->precision > ui_ct->digits)
		arg_data->width -= (arg_data->precision - ui_ct->digits);
	if (arg_data->width_do)
	{
		arg_data->width -= ((ui_ct->digits) + ui_ct->neg);
		if (arg_data->menos == 0)
			white_space(i_s, arg_data);
	}
}

void	init_ui_str(t_uint_ctrl *ui_ct, va_list args, t_argdata *arg_data)
{
	ui_ct->i = va_arg(args, unsigned int);
	ui_ct->digits = 0;
	ui_ct->neg = 0;
	ui_ct->zer_sp = 0;
	ui_ct->a = ui_ct->i;
	arg_mng_uint(arg_data, ui_ct);
}

void	ui_operation(t_uint_ctrl *ui_ct, t_input *i_s)
{
	if (ui_ct->a < 0)
	{
		i_s->f_rt += 1;
		ui_ct->i *= -1;
		ui_ct->a = ui_ct->i;
		ui_ct->neg = 1;
	}
	while (ui_ct->a >= 0)
	{
		ui_ct->a /= 10;
		i_s->f_rt += 1;
		ui_ct->digits += 1;
		if (ui_ct->a == 0)
			break ;
	}
}

void	print_uint(va_list args, t_input *i_s, t_argdata *arg_data)
{
	t_uint_ctrl ui_ct;

	init_ui_str(&ui_ct, args, arg_data);
	ui_operation(&ui_ct, i_s);
	if (ui_ct.zer_sp && ui_ct.neg)
		arg_data->precision -= 1;
	arg_mng_uint2(arg_data, &ui_ct, i_s);
	if (ui_ct.neg)
		write(1, "-", 1);
	if (arg_data->precision_do)
		zer_prec((arg_data->precision - ui_ct.digits), i_s);
	if (arg_data->precision == 0 && ui_ct.i == 0 && arg_data->precision_do)
	{
		if (!arg_data->width_do)
			i_s->f_rt -= 1;
		else
			write(1, " ", 1);
	}
	else
		ft_putuint(ui_ct.i);
	if ((arg_data->menos && arg_data->width_do))
		white_space(i_s, arg_data);
}
