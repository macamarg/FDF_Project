/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:59:04 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 10:59:04 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
int	main()
{
	char str_upper[50] = "run to the hills!!";
	int i = 0;
	printf("%s\n", str_upper);
	while(str_upper[i] != '\0')
	{
		str_upper[i] = ft_toupper(str_upper[i]);
		i++;
	}
	printf("%s\n", str_upper);
}*/
