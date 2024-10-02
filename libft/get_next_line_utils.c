/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:39:56 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/02 14:19:17 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*s_final;

	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	s_final = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
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
	if (s1)
		free (s1);
	return (s_final);
}

int	ft_is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str [i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
