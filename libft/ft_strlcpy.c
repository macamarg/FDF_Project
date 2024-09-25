/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:01:17 by macamarg          #+#    #+#             */
/*   Updated: 2024/04/18 11:01:19 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (size == 0)
		return (j);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
/*
int	main()
{
	printf("strlcpy test\n");
	char *src_cpy;
	char *dst_cpy;

	src_cpy = (char *)malloc(sizeof(char) * (ft_strlen("Hello, world!") + 1));
	dst_cpy = (char *)malloc(sizeof(src_cpy));
	src_cpy = "Hello, world!";
	int	cpy_len = ft_strlcpy(dst_cpy, src_cpy, 13);
	printf("%s len copied %i\n", dst_cpy, cpy_len);
	free(src_cpy);
	free(dst_cpy);
	return (0);
}*/