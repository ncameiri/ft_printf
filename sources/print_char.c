/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:28 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:30 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printchar(va_list args, t_input *i_s, t_argdata *arg_data)
{
	if (arg_data->width_do && arg_data->width > 0)
		arg_data->width -= 1;
	if (arg_data->width_do && arg_data->width < 0)
	{
		arg_data->width += 1;
		arg_data->width *= -1;
		arg_data->menos = 1;
	}
	if (arg_data->menos == 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		i_s->f_rt += 1;
		white_space(i_s, arg_data);
	}
	else
	{
		white_space(i_s, arg_data);
		i_s->f_rt += 1;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	return ;
}
