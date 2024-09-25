/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:46 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:02:48 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memcpy()  function  copies  n bytes from memory area src to memory
//       area dest.  The memory areas must not overlap.

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int     main()
{
        char src[] = "Hello, World!";
        char dest[20];

        ft_memcpy(dest, src, 13);
        printf("Source string: %s\n", src);
        printf("Destination string: %s\n", dest);
        return (0);
}
*/