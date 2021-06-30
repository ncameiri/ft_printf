/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:29:01 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 18:29:04 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	mng_symbols(va_list args, t_input *i_s, t_argdata *arg_data)
{
	if (i_s->in[i_s->ind] == '-')
		menos(i_s, arg_data);
	else if (i_s->in[i_s->ind] == '0')
		zero_flag(i_s, arg_data);
	else if (i_s->in[i_s->ind] == ' ')
	{
		i_s->ind += 1;
		write(1, " ", 1);
		i_s->f_rt += 1;
	}
	else if (ft_isdigit(i_s->in[i_s->ind]) && i_s->in[i_s->ind] != '0')
		arg_data->width = read_width(i_s, arg_data);
	else if (i_s->in[i_s->ind] == '*')
		param_width(args, i_s, arg_data);
	else if (i_s->in[i_s->ind] == '.')
		prec_1(args, i_s, arg_data);
	else if (i_s->in[i_s->ind] == '#')
	{
		i_s->ind += 1;
		arg_data->hash = 1;
	}
}

void	mng_flag(va_list args, t_input *i_s, t_argdata *arg_data)
{
	while ((i_s->ind) < (i_s->m_in))
	{
		if (ft_strchr(FLAG, i_s->in[i_s->ind]))
		{
			mng_symbols(args, i_s, arg_data);
		}
		else if (ft_strchr(SPECIFIER, i_s->in[i_s->ind]))
		{
			mng_specifier(args, i_s, arg_data);
			return ;
		}
		else
		{
			i_s->error = 1;
			return ;
		}
	}
}

int		manage_data(t_input *i_s, va_list args)
{
	t_argdata	flag_data;

	while ((i_s->ind) < (i_s->m_in))
	{
		if (i_s->in[i_s->ind] == '%' && i_s->in[i_s->ind + 1])
		{
			arg_data_init(&flag_data);
			i_s->ind++;
			mng_flag(args, i_s, &flag_data);
		}
		else if (i_s->in[i_s->ind] != '%')
		{
			i_s->f_rt += 1;
			ft_putchar_fd(i_s->in[i_s->ind], 1);
			i_s->ind++;
		}
		else if (i_s->in[i_s->ind] == '%' && !(i_s->in[i_s->ind + 1]))
		{
			i_s->error = 1;
			i_s->ind++;
		}
		else
			(i_s->ind) += 1;
	}
	return (i_s->f_rt);
}

int		ft_printf(const char *input, ...)
{
	int		counter;
	t_input	i_s;
	va_list	args;

	counter = 0;
	if (input)
	{
		input_struct_init(&i_s, (char *)input);
		va_start(args, input);
		counter = manage_data(&i_s, args);
	}
	free(i_s.in);
	return (counter);
}
