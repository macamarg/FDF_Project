/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:58 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:03:01 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memcmp()  function compares the first n bytes (each interpreted as 
// unsigned char) of the memory areas s1 and s2.
// The memcmp() function returns an integer less than, equal to, or greater  
// than  zero  if  the first n bytes of s1 is found, respectively, to be less 
// than, to match, or be greater than the first n bytes of s2.
// For a nonzero return value, the sign is determined by the sign of the 
// difference between  the first pair of bytes (interpreted as unsigned char) 
// that differ in s1 and s2.
// If n is zero, the return value is zero.
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
		i++;
	}
	if (*t1 == *t2)
		return (0);
	else
		return (*t1 - *t2);
}
/*
int	main()
{
	char	*s1 = "Hello, world!";
	char	*s2 = "Hello, world";

	int	i = ft_memcmp(s1, s2, 11);
	printf("%s, %s %i\n", s1, s2, i);
	i = memcmp(s1, s2, 11);
	printf("%s, %s, %i\n", s1, s2, i);	
}*/
