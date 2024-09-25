/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:46:57 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/24 10:50:23 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strrchr() function returns a pointer to the last occurrence of the  
// character  c  in  the string s.
//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*e;
	unsigned char	chr;
	int				i;

	e = (char *)(s);
	i = 0;
	chr = (unsigned char)c;
	while (*e)
	{
		e++;
		i++;
	}
	if (chr == '\0')
		return ((char *)e);
	e--;
	while (i > 0)
	{
		if (*e == chr)
			return ((char *)e);
		e--;
		i--;
	}
	return (NULL);
}

/* int     main()
{
        char    *s = "Hello, world!";
        char    c = 'o';
        char    *r;

        r = ft_strrchr(s, c + 256);
        printf("string %s, char %c, %s %p\n", s, c, r, r);
        r = strrchr(s, c);
        printf("string %s, char %c, %s %p\n", s, c, r, r);
} */
