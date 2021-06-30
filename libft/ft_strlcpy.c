/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:35:32 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/09 10:11:34 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	lenght;
	size_t	i;

	lenght = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	while (src[lenght] != '\0')
	{
		lenght++;
	}
	if (size == 0)
	{
		return (lenght);
	}
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lenght);
}
