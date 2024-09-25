/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:15 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:04:15 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main()
{
	//is_ascii
	printf("is_ascii test\n");
	char c = '0';
	int	ascii = ft_isascii(c);
	if (ascii == 1)
		printf("is_ascii = true");
	else
		printf("is_ascii = false");
}*/