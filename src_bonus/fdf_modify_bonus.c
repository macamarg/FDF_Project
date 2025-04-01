/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:22:07 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/23 14:01:34 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	fdf_hills(t_vars *vars, int factor)
{
	if (vars->map->hills <= 10 && factor == 1)
	{
		vars->map->hills++;
		fdf_modify(vars);
	}
	else if (vars->map->hills > 1 && factor == -1)
	{
		vars->map->hills--;
		fdf_modify(vars);
	}
}

void	fdf_rotate(t_vars *vars, int factor)
{
	if (factor == -1)
		vars->map->rotation_x -= 0.2;
	else if (factor == 1)
		vars->map->rotation_y -= 0.2;
	else if (factor == 2)
		vars->map->rotation += 1;
	fdf_modify(vars);
}

void	fdf_zoom(t_vars *vars, int factor)
{
	vars->map->zoom += 0.1 * factor;
	vars->map->shift_x -= 0.001 * factor;
	vars->map->shift_y -= 0.1 * factor;
	fdf_modify(vars);
}

void	fdf_shift(t_vars *vars, int factor, char c)
{
	if (c == 'x')
		vars->map->shift_x += 0.2 * factor;
	else if (c == 'y')
		vars->map->shift_y += 0.2 * factor;
	fdf_modify(vars);
}

void	fdf_modify(t_vars *vars)
{
	if (vars->map->map_2d)
		free_3d_float(vars->map->map_2d, vars->map->lines, vars->map->rows);
	convert_map(vars->map);
	map_fit(vars->map);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIGTH, HEIGTH);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	fdf_mapdraw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
