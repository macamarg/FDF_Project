/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:59:52 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 12:10:06 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string
//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

static int	is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		j;
	int		end;
	char	*result;

	start = 0;
	j = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set) == 1)
		start++;
	while (is_set(s1[end - 1], set) == 1)
		end--;
	result = (char *)malloc(end - start + 1);
	if (!result)
		return (NULL);
	while ((start) < end)
	{
		result[j] = s1 [start];
		j++;
		start++;
	}
	result[j] = '\0';
	return (result);
}
/*
int	main()
{
	char	*s1 = "*&^ #$	Run to the hills! )(%^@# ";
	char	*set = "@#$%^&*()_+=	 ";
	char	*new;

	new = ft_strtrim(s1, set);
	printf("s1: %s\n set: %s\n new: %s\n", s1, set, new);
	return (0);
}*/
