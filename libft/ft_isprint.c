/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:02 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:04:02 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main()
{
	//is_print test
	printf("is_alnum test\n");
	char c = '@';
	int	print = ft_isalnum(c);
	if (print == 1)
		printf("is_alnum = true");
	else
		printf("is_alnum = false");
}
*/