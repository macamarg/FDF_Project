/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:59:41 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 10:59:43 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’
//#include <stdio.h>
//#include <stdlib.h>
//#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	while (i < len || s[start + i] == '\0')
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main()
{

	char	*s1 = "run to the hills";
	char	*s2;
	char	*s3;

	s2 = ft_substr(s1, 11, 12);
	printf("s1: %s, s2: %s %ld\n", s1, s2, sizeof(s2));
	s3 = ft_substr(s1, 4, 8);
	printf("s1: %s, s3 %s %ld\n", s1, s3, sizeof(s3));
}*/
