/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:34 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:36 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	prec_pointer321(t_argdata *arg_data, char **reshex)
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

void	short_lines_point555(t_input *i_s, t_argdata *arg_data, char *reshex)
{
	int a;

	a = 0;
	if (arg_data->width > 0)
		arg_data->width = arg_data->width - ft_strlen(reshex);
	if (arg_data->width < 0)
	{
		arg_data->width = -arg_data->width - ft_strlen(reshex);
		arg_data->menos = 1;
	}
	if ((arg_data->width > 0) && (arg_data->menos < 1) &&
			arg_data->zero && !arg_data->precision_do)
	{
		zer_prec((arg_data->width), i_s);
		arg_data->width = 0;
	}
	if (arg_data->width > 0 && arg_data->menos < 1 &&
			arg_data->zero && arg_data->precision)
		zer_prec((arg_data->precision - ft_strlen(reshex)), i_s);
	if (arg_data->width > 0 && arg_data->menos == 0)
	{
		a = 1;
		white_space(i_s, arg_data);
	}
}

void	short_lines_point255(t_input *i_s, char *reshex, int cap_x)
{
	int	k;

	k = 0;
	if (!cap_x)
	{
		while (reshex[k] != '\0')
		{
			ft_putchar_fd(reshex[k], 1);
			i_s->f_rt += 1;
			k++;
		}
	}
	else
	{
		while (reshex[k] != '\0')
		{
			ft_putchar_fd(ft_toupper(reshex[k]), 1);
			i_s->f_rt += 1;
			k++;
		}
	}
}

void	only_zero_dig(t_input *i_s)
{
	write(1, "0", 1);
	i_s->f_rt += 1;
}

void	print_hexa(va_list args, t_input *i_s,
		t_argdata *arg_data, int cap_x)
{
	unsigned	int	i;
	char			*reshex;

	i = va_arg(args, unsigned int);
	if (i == 0 && !arg_data->precision_do &&
			!arg_data->width_do && !arg_data->zero)
	{
		only_zero_dig(i_s);
		return ;
	}
	reshex = dex_hex_conv(i);
	invert_str(&reshex);
	nul_hex_x(arg_data, &reshex);
	if (arg_data->precision && arg_data->precision > 0)
		arg_data->precision = arg_data->precision - (ft_strlen(reshex));
	if (arg_data->precision && arg_data->precision < 0)
		arg_data->precision = -arg_data->precision - (ft_strlen(reshex));
	prec_pointer321(arg_data, &reshex);
	short_lines_point555(i_s, arg_data, reshex);
	short_lines_point255(i_s, reshex, cap_x);
	if (arg_data->width > 0 && arg_data->menos > 0)
		white_space(i_s, arg_data);
	free(reshex);
}
