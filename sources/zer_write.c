/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:30:40 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:30:42 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	zer_prec(int num, t_input *i_s)
{
	while (num > 0)
	{
		write(1, "0", 1);
		i_s->f_rt += 1;
		num--;
	}
}