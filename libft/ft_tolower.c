/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:33:15 by ncameiri          #+#    #+#             */
/*   Updated: 2021/01/03 10:33:17 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	re;

	if (c < -1)
		return ((unsigned char)c);
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		re = c;
	return (re);
}
