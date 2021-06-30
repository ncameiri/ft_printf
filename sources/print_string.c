/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:29:35 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 18:29:36 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	arg_mng(t_argdata *arg_data, int len, int i)
{
	if (arg_data->width < 0 && ((arg_data->width) * -1) < len)
		arg_data->width_do = 0;
	if (arg_data->width > 0 && (arg_data->width < len))
		arg_data->width_do = 0;
	if (arg_data->width_do)
	{
		if (arg_data->width > 0)
			arg_data->width -= (i + 1);
		else
			arg_data->width += (i + 1);
	}
}

void	printstring(va_list args, t_input *i_s, t_argdata *arg_data)
{
	char	*content;
	int		i;
	int		a;

	a = 0;
	content = va_arg(args, char *);
	if (content == NULL)
		content = "(null)";
	i = short_lines_str(i_s, arg_data, content);
	while (a <= i)
	{
		i_s->f_rt += 1;
		ft_putchar_fd(content[a], 1);
		a++;
	}
	if (arg_data->width_do == 1 && (arg_data->width < 0 | arg_data->menos == 1))
		white_space(i_s, arg_data);
}

int		short_lines_str(t_input *i_s, t_argdata *arg_data, char *content)
{
	int i;
	int len;
	int prec;

	len = ft_strlen(content);
	if (arg_data->precision_do == 1 && arg_data->precision < len)
	{
		i = (arg_data->precision) - 1;
		len = i;
		prec = arg_data->precision;
	}
	else
	{
		i = len - 1;
		arg_data->precision = 0;
	}
	arg_mng(arg_data, len, i);
	if (arg_data->width_do == 1 && arg_data->menos == 0 && arg_data->width > 0)
		white_space(i_s, arg_data);
	return (i);
}
