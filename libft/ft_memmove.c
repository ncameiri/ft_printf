/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:11:03 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/09 10:06:06 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (n--)
		{
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		}
	}
	else if (src > dst)
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}
