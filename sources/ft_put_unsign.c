/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:29:51 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:29:53 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putuint(unsigned int n)
{
	long	nbr;

	if (n < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = (n * -1);
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putuint(nbr / 10);
	ft_putchar_fd((char)(nbr % 10 + 48), 1);
}
