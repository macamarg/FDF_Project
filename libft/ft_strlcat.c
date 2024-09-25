/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:01:31 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:01:33 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	j;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = 0;
	if (size <= dst_len)
		return (src_len + size);
	while ((dst_len + j) < (size - 1) && src[j] != '\0')
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}
/*
int	main()
{
	printf("strlcat test\n");
	char	src_cat[50] = "world!";
	char dst_cat[50] = "Hello, ";
	printf("dst before %s\n", dst_cat);
	int	cat_len = (ft_strlcat(dst_cat, src_cat, 5));
	printf("%s len cat = %i\n", dst_cat, cat_len);
}*/
