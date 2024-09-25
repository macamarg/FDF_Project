/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:00:34 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:42:40 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//function compares the two strings s1 and s2.
//The strncmp() functions return an integer less than, equal
// to, or greater than zero if s1 (or the first n bytes thereof) is found,
// respectively, to be less than, to match, or be greater than s2.
#include "libft.h"
//#include <stddef.h>
//#include <string.h>
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 == '\0' && *s2 != '\0')
			return (-1);
		if (*s1 != '\0' && *s2 == '\0')
			return (1);
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}
/*
int     main()
{
        char    *s1 = "Hello, world!";
        char    *s2 = "Hello, World";

        int     i = ft_strncmp(s1, s2, 11);
        printf("%s, %s %i\n", s1, s2, i);
        i = strncmp(s1, s2, 11);
        printf("%s, %s, %i\n", s1, s2, i);
}*/
