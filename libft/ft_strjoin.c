/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:01:38 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:01:40 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Allocates (with malloc(3)) and returns a new
//string, which is the result of the concatenation
//of ’s1’ and ’s2’
#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*s_final;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_final = (char *)malloc(len_s1 + len_s2 + 1);
	if (s_final == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (i++ < (len_s1 -1))
		s_final[i] = s1[i];
	while (j++ < (len_s2 - 1))
	{
		s_final[i] = s2[j];
		i++;
	}
	s_final[i] = '\0';
	return (s_final);
}
/*
int	main()
{
	char	*s1 = "Hello, ";
	char	*s2 = "world!";
	char	*final;

	final = ft_strjoin(s1, s2);
	printf("s1 %s, s2 %s, final %s\n", s1, s2, final);

}*/
