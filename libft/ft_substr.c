/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:38:56 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/12 17:44:44 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	new_str(char const *s, char **string, int len, int i)
{
	int		a;
	int		len_s;
	char	*sub_s;

	sub_s = *string;
	len_s = ft_strlen(s);
	a = 0;
	while (i < len_s && len > 0)
	{
		sub_s[a++] = s[i++];
		len--;
	}
	sub_s[a] = '\0';
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*string;
	unsigned int		i;

	i = start;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		string = malloc(1 * sizeof(char));
		if (string == NULL)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	string = malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	new_str(s, &string, len, i);
	return (string);
}
