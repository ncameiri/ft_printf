/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:09 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:11 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	string_nula(t_input *i_s, t_argdata *arg_data)
{
	if (!arg_data->precision_do)
		arg_data->precision = 6;
	if (arg_data->precision > 6)
		arg_data->precision = 6;
	arg_data->width -= 6;
	if (arg_data->menos == 0 && arg_data->width > 6)
		white_space(i_s, arg_data);
	write(1, "(null)", arg_data->precision);
	i_s->f_rt += 6;
	if (arg_data->menos == 1 && arg_data->width > 6)
		white_space(i_s, arg_data);
}
