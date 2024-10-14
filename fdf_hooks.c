/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:57:20 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/14 14:39:56 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

int	kill_vars(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx , vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	if (vars->map != NULL)
		free_map(vars->map);
	free(vars->map);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	printf("%i!\n", keycode);
	if (keycode == 65451)
		fdf_uphills(vars);
	if(keycode == 65453)
		fdf_downhills(vars);
	if (keycode == 65307)
	{
		ft_printf("ESC!\n");
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
