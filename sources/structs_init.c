/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:31:22 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:31:25 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	input_struct_init(t_input *input_struct, char *in)
{
	input_struct->ind = 0;
	input_struct->f_rt = 0;
	input_struct->error = 0;
	input_struct->m_in = ft_strlen(in);
	input_struct->in = ft_strdup(in);
}

void	arg_data_init(t_argdata *arg_data)
{
	arg_data->flags_do = 0;
	arg_data->width = 0;
	arg_data->menos = 0;
	arg_data->zero = 0;
	arg_data->ponto = 0;
	arg_data->asteris = 0;
	arg_data->precision_do = 0;
	arg_data->width_do = 0;
	arg_data->precision = 0;
	arg_data->flags = "";
	arg_data->hash = 0;
	arg_data->length = "";
	arg_data->final_out = "";
}
