/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:31:12 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:31:14 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	read_width(t_input *i_s, t_argdata *arg_data)
{
	char	temp[10];
	int		i;

	i = 0;
	arg_data->width_do = 1;
	while (ft_isdigit((i_s->in[i_s->ind])))
	{
		temp[i] = i_s->in[i_s->ind];
		i_s->ind += 1;
		i++;
	}
	temp[i] = '\0';
	return (ft_atoi(temp));
}
