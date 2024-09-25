/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:00:15 by macamarg          #+#    #+#             */
/*   Updated: 2024/08/09 11:47:13 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strnstr() function locates the first occurrence of the null-terminated
//  string little in the string big, where not more than len characters are 
//  searched.  Characters that appear after a ‘\0’ character are not searched.
//  Since the strnstr() function is a FreeBSD specific API, it should only 
//  be used when portability is not a concern.
//#include "libft.h"
#include <stddef.h>
#include <stdio.h>
//#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	j;

	j = 0;
	if (!big)
		return (NULL);
	if (!little || little [j] == '\0')
		return ((char *)big);
	while (*big && len > 0)
	{
		j = 0;
		while (*(big + j) == *(little + j) && len > (size_t)j)
			j++;
		if (*(little + j) == '\0')
			return ((char *)(big));
		len--;
		big++;
	}
	if (*(little + j) == '\0')
		return ((char *)(big));
	else
		return (0);
}
/*
int	main()
{
	char	*big = "";
	char	*little = "aabc";
	char	*little1 = "\0";
	char	*result;
	//char	*result1;
	char	*result2;
	//char	*result3;

	result = ft_strnstr(big, little, 9);
	printf("big %s, little %s, result %s %p\n", big, little, result, result);
	//result1 = strnstr(big, little, 13);
	//printf("big %s, little %s, result %s %p\n", big, little, result1, result1);
	result2 = ft_strnstr(big, little1, 13);
	printf("big %s, little %s, result %s %p\n", big, little1, result2, result2);
	//result3 = strnstr(big, little1, 13);
	//printf("big %s, little %s, result %s %p\n",
	 big, little1, result3, result3);
}*/