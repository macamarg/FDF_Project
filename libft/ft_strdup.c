/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:01:54 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:05:46 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The  strdup() function returns a pointer to a new string which is a du‐
//       plicate of the string s
#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

int	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*result;

	len = ft_strlen(s);
	i = 0;
	result = (char *)malloc(len + 1);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main()
{
	char	*s = "Run to the hills";
	char	*s1;
	char	*s2;

	s1 = ft_strdup(s);
	s2 = strdup(s);
	printf("s: %s s1: %s %ld\n", s, s1, sizeof(s1));
	printf("s: %s s2: %s %ld\n", s, s2, sizeof(s2));
}*/
