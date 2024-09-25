/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:00:47 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:00:47 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
/*
char	func(unsigned int i, char c)
{
	printf("%i %c\n", i, c);
	return (c);
}

int	ft_strlen(const char *s);
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	char	*str = "Run to the hills";
	char	*result;

	result = ft_strmapi(str, &func);
	printf("%s %s\n", str, result);
}*/
