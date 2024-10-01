/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:07:58 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/03 14:22:01 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int is_in_base(const char digit)
{
	int	result;
	
	result = -1;
	if ('0' <= digit && digit <= '9')
		result = digit - 48;
	else if ('a' <= digit && digit <= 'f')
		result = 10 + digit - 'a';
	else if ('A' <= digit && digit <= 'F')
		result = 10 + digit - 'A';
	else if (digit == 'x' || digit == 'X')
		result = 0;
	return (result);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int result = 0;
	int signal = 1;
	int in_base = 0;

	if ((str[i] != '\0'))
	{
		while((9 <= str[i] && str[i] <= 13) || str[i] == 32)
			i++;
		if(str[i] == '-' || str[i] == '+')
		{
			if(str[i] == '-')
				signal *= -1;
			i++;
		}
		in_base = is_in_base(str[i]);
		while(0 <= in_base  && in_base <= str_base)
		{
			result *= str_base;
			result += in_base;
			i++;
			in_base = is_in_base(str[i]);
		}
	}
	return(result * signal);
}

// int	main(void)
// {
// 	printf("%i", ft_atoi_base("  	0xFF0000 ", 16));
// }