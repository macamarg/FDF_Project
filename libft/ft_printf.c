/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:42:51 by macamarg          #+#    #+#             */
/*   Updated: 2024/08/09 12:00:20 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	ft_printf_check(char c, va_list args, int count)
{
	if (!args)
		return (count);
	if (c == 'c')
		count += ft_putchar_count(va_arg(args, unsigned int));
	else if (c == 's')
		count += ft_string(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		count += ft_number(va_arg(args, int));
	else if (c == 'p')
		count += ft_pointer(va_arg(args, void *));
	else if (c == 'X' || c == 'x')
		count += ft_hexa(va_arg(args, unsigned int), c);
	else if (c == 'u')
		count += ft_unsigend_number(va_arg(args, unsigned int));
	else if (c == '%')
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;
	int		count;

	if (!input)
		return (-1);
	i = 0;
	count = 0;
	va_start (args, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			count = ft_printf_check(input[i], args, count);
		}
		else
			count += ft_putchar_count(input[i]);
		i++;
	}
	va_end(args);
	return (count);
}
