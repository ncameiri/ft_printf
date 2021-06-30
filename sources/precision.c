/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:22 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:24 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	read_precision(t_input *i_s, t_argdata *arg_data, va_list args)
{
	char	temp[10];
	int		i;

	i_s->ind += 1;
	if (i_s->in[i_s->ind] == '*')
	{
		i = va_arg(args, int);
		if (i < 0)
			arg_data->precision_do = 0;
		arg_data->precision = i;
		i_s->ind += 1;
		return ;
	}
	i = 0;
	while (i_s->in && ft_isdigit(i_s->in[i_s->ind]))
	{
		temp[i] = i_s->in[i_s->ind];
		i++;
		i_s->ind += 1;
	}
	temp[i] = '\0';
	arg_data->precision = ft_atoi(temp);
}
