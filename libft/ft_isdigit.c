/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:09 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:04:09 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main()
{
	//is_digit test
	printf("is_digit test\n");
	char d = '0';
	int	digit = ft_isdigit(d);
	if (digit == 1)
		printf("is_alpha = true");
	else
		printf("is_aplha = false");
}
*/