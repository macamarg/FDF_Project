/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:57:20 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/15 14:23:02 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"

int	kill_vars(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	if (vars->map != NULL)
		free_map(vars->map);
	free(vars->map);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%i!\n", keycode);
	if (keycode == 104)
		fdf_uphills(vars);//h
	else if (keycode == 106)
		fdf_downhills(vars);//j
	else if (keycode == 114)
		fdf_rotate(vars, -1);//r
	else if (keycode == 101)
		fdf_rotate(vars, 1);//e
	else if (keycode == 116)
		fdf_rotate(vars, 2);//t
	else if (keycode == 122)
		fdf_zoom(vars, 1);//z
	else if (keycode == 120)
		fdf_zoom(vars, -1);//x
	else if (keycode == 32)
		fdf_reinit(vars);//space
	else if (keycode == 100)
		fdf_shift(vars, -1, 'x');//d
	else if (keycode == 97)
		fdf_shift(vars, 1, 'x');//a
	else if (keycode == 119)
		fdf_shift(vars, -1, 'y');//w
	else if (keycode == 115)
		fdf_shift(vars, 1, 'y');//s
	else if (keycode == 65307)
		kill_vars(vars);//esc
	return (0);
}

int	mouse_hook(int keycode)
{
	printf("Hello from mouse_hook!\n");
	if (keycode == 1)
		printf("1 = left\n");
	return (0);
}
