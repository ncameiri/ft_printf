/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:34:55 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/08 12:37:26 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char			*arra;
	size_t			i;
	unsigned int	total;

	total = nitems * size;
	arra = malloc(nitems * size);
	if (arra == NULL)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		arra[i] = 0;
		total--;
		i++;
	}
	return ((void *)arra);
}
