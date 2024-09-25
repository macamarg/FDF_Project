/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:11:51 by macamarg          #+#    #+#             */
/*   Updated: 2024/05/03 13:15:42 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa(unsigned int x, char c)
{
	char	*str_hexa;
	int		count;

	if (c == 'x')
		str_hexa = (char *)ft_itoa_base(x, "0123456789abcdef");
	else
		str_hexa = (char *)ft_itoa_base(x, "0123456789ABCDEF");
	count = ft_string(str_hexa);
	free (str_hexa);
	return (count);
}
