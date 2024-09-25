/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:41 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:02:52 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//       The  memmove()  function  copies n bytes from memory area src to memory
//       area dest.  The memory areas may overlap: copying takes place as though
//       the  bytes in src are first copied into a temporary array that does not
//       overlap src or dest, and the bytes are then copied from  the  temporary
//       array to dest.
//#include <stddef.h>
//#include <stdio.h>

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s && d < (s + n))
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main()
{
	char src[] = "Hello, World!";
	char dest[20];

	ft_memmove(dest, src, 13);
	printf("Source string: %s\n", src);
	printf("Destination string: %s\n", dest);
	return (0);
}*/
