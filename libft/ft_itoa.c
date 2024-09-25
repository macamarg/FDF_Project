/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:57 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:03:58 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

static int	str_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while ((n) > 9 || (n) < -9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	put_nbr_str(char *result, int n, int size)
{
	size--;
	while (size >= 0)
	{
		if (n < 0)
			result[size] = ((-1 * (n % 10)) + 48);
		else
			result[size] = ((n % 10) + 48);
		size--;
		if (n < 0 && n >= -9)
		{
			result[0] = '-';
			size--;
		}
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	size = str_size(n);
	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	put_nbr_str(result, n, size);
	return (result);
}
/*
int	main()
{
	char	*result;

	result = ft_itoa(-2147483647);
	printf("int -2147483647 str: %s", result);
	free(result);
}*/
