/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:57:20 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/25 15:03:22 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

int	kill_vars(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.img.img);//free img 5
	mlx_destroy_window(vars.mlx , vars.win);//3
	mlx_destroy_display(vars.mlx);//close and free mlx
	free(vars.mlx);//2
	if (vars.map != NULL)
		free_map(vars.map);
	exit (0);
}

int	key_hook(int keycode, t_vars vars)
{
	printf("Hello from key_hook!\n");
	printf("%i!\n", keycode);
	if (keycode == 32)
		printf("space!\n");
	if (keycode == 65307)
	{
		printf("ESC!\n");
		kill_vars(vars);
	}
	return (0);
}

int	mouse_hook(int keycode)
{
	printf("Hello from mouse_hook!\n");
	if (keycode == 1)
		printf("1 = left\n");
	return (0);
}