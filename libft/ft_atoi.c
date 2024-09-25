/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:44 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:04:44 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	signal;
	int	i;

	signal = 1;
	i = 0;
	result = 0;
	while (nptr[i] != '\0')
	{
		while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 15))
			i++;
		if (nptr[i] == '+' || nptr[i] == '-')
		{
			if (nptr[i] == '-')
				signal = -signal;
			i++;
		}
		while ('0' <= nptr[i] && nptr[i] <= '9')
		{
			result = result * 10 + (nptr[i] - 48);
			i++;
		}
		return (signal * result);
	}
	return (signal * result);
}
/*
int	main(void)
{
	printf("%i", ft_atoi("  	-21474 83647"));
}*/
