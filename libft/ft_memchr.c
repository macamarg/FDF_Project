/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:06 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:03:08 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memchr() function scans the initial n bytes of the memory area pointed 
to by s for the first instance of c. Both c and the bytes of the memory area 
pointed to by s are interpreted as unsigned char.
*/
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	i = 0;
	ptr = (const unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((char *)s);
		s++;
		i++;
	}
	return (0);
}
/*
int     main()
{
        char    *s = "";
        char    c = 'e';
        char    *r;

        r = (char *)ft_memchr(s, c, 13);
        printf("string %s, char %c, %s %p\n", s, c, r, r);
        r = (char *)memchr(s, c, 13);
        printf("string %s, char %c, %s %p\n", s, c, r, r);

}
*/
