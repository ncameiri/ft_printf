/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:31:29 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:31:31 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	menos(t_input *i_s, t_argdata *arg_data)
{
	arg_data->menos += 1;
	(i_s->ind) += 1;
}

void	zero_flag(t_input *i_s, t_argdata *arg_data)
{
	(i_s->ind) += 1;
	arg_data->zero = 1;
}

void	param_width(va_list args, t_input *i_s, t_argdata *arg_data)
{
	arg_data->width = va_arg(args, int);
	arg_data->width_do = 1;
	(i_s->ind) += 1;
}

void	prec_1(va_list args, t_input *i_s, t_argdata *arg_data)
{
	arg_data->precision_do = 1;
	read_precision(i_s, arg_data, args);
}
