/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:39:25 by macamarg          #+#    #+#             */
/*   Updated: 2024/08/09 11:59:49 by macamarg         ###   ########.fr       */
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

static int	len_str(long pointer, int base_len)
{
	int			len;
	long int	numb;

	len = 1;
	numb = pointer;
	if (numb < 0)
	{
		len++;
		numb = -numb;
	}
	while (numb >= base_len)
	{
		numb = numb / base_len;
		len++;
	}
	return (len);
}

static void	ft_putnbr_base(char *str_nb, long nbr, int len, char *base)
{
	int			base_len;
	long int	nbr_s;

	base_len = ft_base_len(base);
	str_nb[len] = '\0';
	len--;
	nbr_s = nbr;
	if (nbr < 0)
		nbr = -nbr;
	while (len >= 0)
	{
		str_nb[len] = (base[nbr % base_len]);
		len--;
		nbr = nbr / base_len;
	}
	if (nbr_s < 0)
		str_nb[0] = '-';
}

char	*ft_itoa_base(unsigned long long int num, char *base)
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
	printf("%p itoa_base %s\n",  &i, 
	ft_itoa_base((size_t)&i, "0123456789abcdef"));
	printf(" %s\n", ft_itoa_base(140727777887320, "0123456789abcdef"));
	
}*/