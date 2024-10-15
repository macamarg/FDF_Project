/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:22:07 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/15 14:38:17 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_uphills(t_vars *vars)
{
	if (vars->map->hills <= 10)
	{
		vars->map->hills++;
		fdf_modify(vars);
	}
}

void	fdf_downhills(t_vars *vars)
{
	if (vars->map->hills > 1)
	{
		vars->map->hills--;
		fdf_modify(vars);
	}
}

void	fdf_reinit(t_vars *vars)
{
	vars->map->zoom = 1;
	vars->map->hills = 1;
	vars->map->color_stat = 0;
	vars->map->rotation = 1;
	fdf_modify(vars);
}

void	fdf_rotate(t_vars *vars, int factor)
{
	if (factor == -1 && vars->map->rotation <= 1 && vars->map->rotation > -0.8)
		vars->map->rotation -= 0.1;
	else if (factor == 1 && vars->map->rotation < 1
		&& vars->map->rotation >= -0.9)
		vars->map->rotation += 0.1;
	fdf_modify(vars);
}

void	fdf_zoom(t_vars *vars, int factor)
{
	int	i;
	int	j;

	i = -1;
	vars->map->zoom += 0.1 * factor;
	while (++i < vars->map->lines)
	{
		j = -1;
		while (++j < vars->map->rows)
		{
			vars->map->map_2d[i][j][0] -= WIGTH / 16;
			vars->map->map_2d[i][j][0] *= vars->map->zoom;
			vars->map->map_2d[i][j][1] -= HEIGTH / 16;
			vars->map->map_2d[i][j][1] *= vars->map->zoom;
		}
	}
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIGTH, HEIGTH);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	fdf_mapdraw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
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
