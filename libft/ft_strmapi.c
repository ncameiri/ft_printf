/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:34:15 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/09 10:12:10 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*here;

	i = 0;
	if (!s || !f)
		return (NULL);
	here = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (here == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		here[i] = f(i, s[i]);
		i++;
	}
	here[i] = '\0';
	return (here);
}
