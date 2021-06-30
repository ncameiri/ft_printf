/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:33:01 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/09 09:54:08 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char		*str1_ptr;
	const unsigned char		*str2_ptr;
	int						i;

	str1_ptr = (unsigned char *)str1;
	str2_ptr = (unsigned char *)str2;
	i = 0;
	while (n > 0)
	{
		if (str1_ptr[i] != str2_ptr[i])
			return (str1_ptr[i] - str2_ptr[i]);
		i++;
		n--;
	}
	return (0);
}
