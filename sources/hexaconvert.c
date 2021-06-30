/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:29:58 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/05 15:29:59 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*dex_hex_conv(unsigned long long int n)
{
	char		hexnumb[19];
	long long	temp;
	int			i;

	i = 0;
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
		{
			hexnumb[i] = temp + 48;
			i++;
		}
		else
		{
			hexnumb[i] = temp + 87;
			i++;
		}
		n = n / 16;
	}
	hexnumb[i] = '\0';
	return (ft_strdup(hexnumb));
}

void	invert_str(char **str)
{
	char	temp[100];
	char	*aux;
	int		i;
	int		k;

	aux = *str;
	i = 0;
	k = ft_strlen(aux);
	temp[k--] = '\0';
	while (aux[i] != '\0')
	{
		temp[k] = aux[i];
		k--;
		i++;
	}
	free(*str);
	*str = ft_strdup(temp);
}

void	nul_hex_x(t_argdata *arg_data, char **reshex)
{
	char *ptr;
	char *ptr2;

	ptr = *reshex;
	if (arg_data->hash)
	{
		ptr2 = ft_strjoin("0x0", ptr);
		free(ptr);
		reshex = &ptr2;
	}
	if (*reshex[0] == 0 && !arg_data->width_do)
	{
		free(ptr);
		*reshex = ft_strdup("");
	}
	if (*reshex[0] == 0 && arg_data->width_do && !arg_data->precision_do)
	{
		free(ptr);
		*reshex = ft_strdup("0");
	}
}
