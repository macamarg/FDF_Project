/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:28 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:04:28 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main()
{
	//is_alnum test
	printf("is_alnum test\n");
	char c = '0';
	int	alnum = ft_isalnum(c);
	if (alnum == 1)
		printf("is_alnum = true");
	else
		printf("is_alnum = false");
}*/