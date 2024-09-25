/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:00 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/23 10:40:29 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The  strchr() function returns a pointer to the first occurrence of the
//       character c in the string s
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main()
{
	char	*s = "Hello, world!";
	char	c = 'e';
	char	*r;

	r = ft_strchr(s, c);
	printf("string %s, char %c, %s %p\n", s, c, r, r);
	r = strchr(s, c);
	printf("string %s, char %c, %s %p\n", s, c, r, r);
}*/
