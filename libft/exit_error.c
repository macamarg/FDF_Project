/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:17:43 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/23 11:13:35 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	exit_error(char *error_msg, int ret)
{
	ft_putstr_fd(error_msg, 2);
	exit(ret);
}

int	exit_error_free(char *error_msg, int ret, void *freeble)
{
	free (freeble);
	ft_putstr_fd(error_msg, 2);
	exit(ret);
}

void	error_free_array(char *msg, int ret, void **freeble, int i)
{
	while (i >= 0)
	{
		free(freeble[i]);
		i--;
	}
	exit_error_free (msg, ret, freeble);
}
