/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:39:25 by macamarg          #+#    #+#             */
/*   Updated: 2024/08/09 12:17:11 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

static int	len_str(unsigned long long int pointer, int base_len)
{
	int						len;
	unsigned long long int	numb;

	len = 1;
	numb = pointer;
	if ((int)numb < 0)
	{
		numb = -numb;
	}
	while (numb >= (unsigned long long int)base_len)
	{
		numb = numb / base_len;
		len++;
	}
	return (len);
}

static void	ft_putnbr_base(char *str_nb, unsigned long long int nbr,
int len, char *base)
{
	int		base_len;

	base_len = ft_base_len(base);
	str_nb[len] = '\0';
	len--;
	while (len >= 0)
	{
		str_nb[len] = (base[nbr % base_len]);
		len--;
		nbr = nbr / base_len;
	}
}

char	*ft_itoa_pointer(unsigned long long int num, char *base)
{
	int		len;
	char	*str;
	int		base_len;
	long	nb;

	nb = num;
	base_len = ft_base_len(base);
	len = len_str(nb, base_len);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	ft_putnbr_base(str, nb, len, base);
	return ((char *)str);
}
/*
int	main()
{
	size_t i;
	
	i = 1;
	printf("%p %s\n", &i, ft_itoa_base(110224, "0123456789abcdef"));
	printf("%p %s\n", &i, ft_itoa_base(110224, "0123456789"));
	printf("%p itoa_base %s\n",  
	&i, ft_itoa_base((size_t)&i, "0123456789abcdef"));
	printf(" %s\n", ft_itoa_base(140727777887320, "0123456789abcdef"));
	
}*/