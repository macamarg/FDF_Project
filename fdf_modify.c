/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:22:07 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/14 14:43:00 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_uphills(t_vars *vars)
{
	if (vars->map->hills < 5)
	{
		vars->map->hills++;
		if(vars->map->map_2d)
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
}

void	fdf_downhills(t_vars *vars)
{
	if (vars->map->hills > 1)
	{
		vars->map->hills--;
		if(vars->map->map_2d)
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
}
