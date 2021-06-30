/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:38:58 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/09 10:10:43 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)str;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
		new_str++;
	}
	return (new_str);
}
