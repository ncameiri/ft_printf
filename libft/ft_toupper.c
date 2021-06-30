/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:32:51 by ncameiri          #+#    #+#             */
/*   Updated: 2021/01/03 10:32:53 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	re;

	if (c < -1)
		return ((unsigned char)c);
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		re = c;
	return (re);
}
