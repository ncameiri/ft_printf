/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 10:08:22 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/09 10:06:15 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n > 0)
	{
		*ptr++ = (unsigned char)c;
		n--;
	}
	return (str);
}
