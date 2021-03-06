/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:14:46 by ncameiri          #+#    #+#             */
/*   Updated: 2021/01/03 10:17:37 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!*little)
		return ((char *)big);
	while (big[a] != '\0' && a < len)
	{
		b = 0;
		while (big[a + b] != '\0' && big[a + b] == little[b]
			&& (a + b) < len && little[b] != '\0')
		{
			if (little[b + 1] == '\0')
				return ((char *)&(big[a]));
			b++;
		}
		a++;
	}
	return (0);
}
