/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:09:01 by macamarg          #+#    #+#             */
/*   Updated: 2024/05/03 13:17:42 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	return (i);
}
