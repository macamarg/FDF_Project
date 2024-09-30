/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:54:07 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/30 13:02:08 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_color(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	g_color(char *str)
{
	char	*temp;
	int		result;

	result = 0;
	temp = str;
	while (*temp)
	{
		if (*temp == 'x')
		{
			result = ft_atoi_base (++temp, 16);
		}
		temp++;
	}
	return (result);
}
