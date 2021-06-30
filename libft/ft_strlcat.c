/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:37:18 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/09 10:11:17 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size < dst_size)
		return (src_size + size);
	while (src[i] != '\0' && dst_size < (size - 1))
	{
		dst[dst_size] = src[i];
		i++;
		dst_size++;
	}
	dst[dst_size] = '\0';
	return (src_size + ft_strlen(dst) - i);
}
