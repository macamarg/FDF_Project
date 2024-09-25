/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:59:22 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 10:59:22 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
int	main()
{
	char str_upper[50] = "RUN TO THE HILLS!!!";
	int i = 0;
	printf("%s\n", str_upper);
	while (str_upper[i] != '\0')
	{
		str_upper[i] = ft_tolower(str_upper[i]);
		i++;
	}
	printf("%s\n", str_upper);
}*/
