/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:59:44 by macamarg          #+#    #+#             */
/*   Updated: 2024/05/03 13:14:46 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_pointer(void *pointer)
{
	char					*str_ptr;
	char					*hexa_str;
	int						count;
	long long unsigned int	l_pointer;

	if (pointer)
	{
		l_pointer = (long long unsigned int)pointer;
		if ((int)l_pointer < 0)
			l_pointer = -l_pointer;
		hexa_str = "0123456789abcdef";
		write (1, "0x", 2);
		str_ptr = ft_itoa_pointer(l_pointer, hexa_str);
		count = ft_string(str_ptr);
		free (str_ptr);
		return (count + 2);
	}
	else
	{
		write(1, "(nil)", 5);
		return (5);
	}
}
