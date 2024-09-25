/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:14:43 by macamarg          #+#    #+#             */
/*   Updated: 2024/05/03 13:15:23 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_unsigend_number(unsigned int nbr)
{
	char	*str_nbr;
	int		count;

	str_nbr = (char *)ft_itoa_base (nbr, "0123456789");
	count = ft_string(str_nbr);
	free (str_nbr);
	return (count);
}

int	ft_number(int nbr)
{
	char	*str_nbr;
	int		count;

	str_nbr = (char *)ft_itoa_base (nbr, "0123456789");
	count = ft_string(str_nbr);
	free (str_nbr);
	return (count);
}
