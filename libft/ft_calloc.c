/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:34 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:04:34 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*dest;
	size_t	size_check;

	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = 1;
	}
	size_check = nelem * elsize;
	if (size_check / elsize != nelem)
		return (0);
	dest = malloc(nelem * elsize);
	if (dest == NULL)
		return (NULL);
	else
		ft_bzero(dest, nelem);
	return (dest);
}

/* int	main()
{
	void *result;
	int	i = 0;
	result = ft_calloc(8, 8);
	while(i < 8)
	{
		result[i] += 48;
		i++;
	}
	printf("%s\n", (char *)result);
}
 */