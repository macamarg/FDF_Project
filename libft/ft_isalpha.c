/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:22 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:04:22 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
int	main()
{
	//is alpha test
	printf("is_alpha test\n");
	char c = 'M';
	int	alpha = ft_isalpha(c);
	if (alpha == 1)
		printf("is_alpha = true");
	else
		printf("is_aplha = false");
}*/
