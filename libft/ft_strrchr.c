/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:12:25 by ncameiri          #+#    #+#             */
/*   Updated: 2021/01/03 10:12:43 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = 0;
	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == c)
		{
			last = ((char *)str);
		}
		str++;
	}
	return (last);
}
