/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:25 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/30 14:23:40 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned long color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned long *)dst = color;
}

void	fdf_mapdraw(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->map->lines)
	{
		j = -1;
		while (++j < vars->map->rows)
		{
			vars->map->x_f = vars->map->map_2d[i][j][0];
			vars->map->y_f = vars->map->map_2d[i][j][1];
			mlx_pixel_put(&vars->mlx, &vars->win, vars->map->x_f,
				vars->map->y_f, vars->map->map_color[i][j]);
		}
	}
}

//mlx_pixel_put(mlx, mlx_win, 200 + i, 200 + j, 0xff0000);