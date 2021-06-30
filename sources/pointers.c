/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:16 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:17 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	prec_pointer(t_argdata *arg_data, char **reshex)
{
	char	*aux;
	int		ind;
	char	*aux2;

	ind = 0;
	if (arg_data->precision > 0)
	{
		if (!(aux = (char*)malloc(sizeof(char) * (arg_data->precision + 1))))
			return ;
		while (ind < arg_data->precision)
		{
			aux[ind] = '0';
			ind++;
		}
		aux[ind] = '\0';
		aux2 = *reshex;
		*reshex = ft_strjoin(aux, aux2);
		free(aux2);
		free(aux);
	}
}

void	short_lines_point(t_input *i_s, t_argdata *arg_data, char *reshex)
{
	if (arg_data->width > 0)
		arg_data->width = arg_data->width - ft_strlen(reshex) - 2;
	else if (arg_data->width < 0)
	{
		arg_data->width = -(arg_data->width) - ft_strlen(reshex) - 2;
		arg_data->menos = 1;
	}
	if (arg_data->width > 0 && arg_data->menos < 1)
		white_space(i_s, arg_data);
}

void	short_lines_point2(t_input *i_s, char *reshex)
{
	int k;

	k = 0;
	while (reshex[k] != '\0')
	{
		ft_putchar_fd(reshex[k], 1);
		i_s->f_rt += 1;
		k++;
	}
}

void	print_point(va_list args, t_input *i_s, t_argdata *arg_data)
{
	long long	i;
	char		*reshex;

	i = va_arg(args, long long);
	reshex = dex_hex_conv(i);
	invert_str(&reshex);
	if (reshex[0] == '\0')
	{
		free(reshex);
		reshex = ft_strdup("0");
	}
	arg_data->precision = arg_data->precision - (ft_strlen(reshex));
	prec_pointer(arg_data, &reshex);
	short_lines_point(i_s, arg_data, reshex);
	write(1, "0x", 2);
	i_s->f_rt += 2;
	short_lines_point2(i_s, reshex);
	if (arg_data->width > 0 && arg_data->menos > 0)
		white_space(i_s, arg_data);
	free(reshex);
}
