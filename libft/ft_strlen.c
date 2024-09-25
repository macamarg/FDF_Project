/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:01:03 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:01:03 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main()
{
	//strlen test
	printf("strlen test\n");
	char *str1 = "Hello, world!";
	int	len = ft_strlen(str1);
	printf("%s len = %i\n", str1, len);
}*/
