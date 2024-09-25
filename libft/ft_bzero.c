/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:39 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:04:39 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>
//void    *ft_memset(void *s, int c, size_t n);

void	*ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
	return (s);
}
/*
int	main()
{
        char *s;
	int     n = 7;
	int	i = 0;

	printf("bzero test\n");
        s = (char *)malloc(n);
        ft_bzero(s, n);
	printf("%s\n", s);
	while (i < 8)
        {
                s[i] += 48;
                i++;
        }

        printf("%s\n", s);
        free(s);

}*/
