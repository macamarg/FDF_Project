/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:01:47 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:01:47 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
/*
void	func(unsigned int i, char *s)
{
	printf("%i, %s\n", i, s);
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, (s + i));
		i++;
	}
}
/*
int	main(void)
{
	char	*str = "Run to the hills";

	ft_striteri(str, &func);
	printf("after function: %s", str);
}*/
