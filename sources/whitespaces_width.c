/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespaces_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:31:40 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:31:42 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	white_space(t_input *i_s, t_argdata *arg_data)
{
	int i;

	i = 0;
	i = arg_data->width;
	if (i < 0)
		i *= -1;
	while (i > 0)
	{
		ft_putchar_fd(' ', 1);
		i_s->f_rt++;
		i--;
	}
	return (0);
}
