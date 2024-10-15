/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:25 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/15 13:48:33 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned long color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned long *)dst = color;
}

void	draw_line(t_vars *vars, t_draw dm)
{
	dm.dx = abs(dm.s[0] - dm.e[0]);
	dm.dy = -abs(dm.s[1] - dm.e[1]);
	dm.err = dm.dx - dm.dy;
	if (dm.s[0] > dm.e[0])
		dm.stepx = -1;
	if (dm.s[1] > dm.e[1])
		dm.stepy = -1;
	while (dm.s[0] != dm.e[0] && dm.s[1] != dm.e[1])
	{
		dm.sx = (5 * WIGTH / 7) - dm.s[0];
		dm.sy = dm.s[1];
		if ((dm.sx >= 0 && dm.sx <= WIGTH) && (dm.sy >= 0 && dm.sy <= HEIGTH))
			my_mlx_pixel_put(&vars->img, dm.sx, dm.sy, dm.color[0]);
		dm.e2 = 2 * dm.err;
		if (dm.e2 >= dm.dy)
		{
			dm.err += dm.dy;
			dm.s[0] += dm.stepx;
		}
		if (dm.e2 <= dm.dx)
		{
			dm.err += dm.dx;
			dm.s[1] += dm.stepy;
		}
	}
}

// void	draw_line(t_vars *vars, t_draw dm)
// {
// 	dm.dx = (dm.s[0] - dm.e[0]);
// 	dm.dy = (dm.s[1] - dm.e[1]);
// 	dm.pixels = sqrt((dm.dx * dm.dx)+(dm.dy * dm.dy));
// 	dm.stepx = 1;
// 	dm.stepy = 1;
// 	if (dm.s[0] > dm.e[0])
// 		dm.stepx = -1;
// 	if(dm.s[1] > dm.e[1])
// 		dm.stepy = -1;
// 	while(dm.pixels >= 0)
// 	{
// 		dm.sx = (5 * WIGTH / 7) - dm.s[0];
// 		dm.sy = dm.s[1];
// 		if((dm.sx >= 0 && dm.sx <= WIGTH) && (dm.sy >= 0 && dm.sy <= HEIGTH))
// 			my_mlx_pixel_put(&vars->img, dm.sx, dm.sy, dm.color[0]);
// 		dm.s[0] += dm.stepx;
// 		dm.s[1] += dm.stepy;
// 	}
// }

void	draw_vert(t_vars *vars, t_draw dm)
{
	if (dm.j == (vars->map->rows - 2))
	{
		dm.stepx = 1;
		dm.stepy = 1;
		dm.s[0] = vars->map->map_2d[dm.i][dm.j + 1][0];
		dm.s[1] = vars->map->map_2d[dm.i][dm.j + 1][1];
		dm.e[0] = vars->map->map_2d[dm.i + 1][dm.j + 1][0];
		dm.e[1] = vars->map->map_2d[dm.i + 1][dm.j + 1][1];
		dm.color[0] = vars->map->map_color[dm.i][dm.j + 1][1];
		dm.color[1] = vars->map->map_color[dm.i + 1][dm.j + 1][1];
		draw_line(vars, dm);
	}
	dm.stepx = 1;
	dm.stepy = 1;
	dm.s[0] = vars->map->map_2d[dm.i][dm.j][0];
	dm.s[1] = vars->map->map_2d[dm.i][dm.j][1];
	dm.e[0] = vars->map->map_2d[dm.i][dm.j + 1][0];
	dm.e[1] = vars->map->map_2d[dm.i][dm.j + 1][1];
	dm.color[0] = vars->map->map_color[dm.i][dm.j][1];
	dm.color[1] = vars->map->map_color[dm.i][dm.j + 1][1];
	draw_line(vars, dm);
}

void	draw_hor(t_vars *vars, t_draw dm)
{
	if (dm.i == (vars->map->lines - 2))
	{
		dm.stepx = 1;
		dm.stepy = 1;
		dm.s[0] = vars->map->map_2d[dm.i + 1][dm.j][0];
		dm.s[1] = vars->map->map_2d[dm.i + 1][dm.j][1];
		dm.e[0] = vars->map->map_2d[dm.i + 1][dm.j + 1][0];
		dm.e[1] = vars->map->map_2d[dm.i + 1][dm.j + 1][1];
		dm.color[0] = vars->map->map_color[dm.i + 1][dm.j][1];
		dm.color[1] = vars->map->map_color[dm.i + 1][dm.j + 1][1];
		draw_line(vars, dm);
	}
	dm.stepx = 1;
	dm.stepy = 1;
	dm.s[0] = vars->map->map_2d[dm.i][dm.j][0];
	dm.s[1] = vars->map->map_2d[dm.i][dm.j][1];
	dm.e[0] = vars->map->map_2d[dm.i + 1][dm.j][0];
	dm.e[1] = vars->map->map_2d[dm.i + 1][dm.j][1];
	dm.color[0] = vars->map->map_color[dm.i][dm.j][1];
	dm.color[1] = vars->map->map_color[dm.i + 1][dm.j][1];
	draw_line(vars, dm);
}

void	fdf_mapdraw(t_vars *vars)
{
	t_draw	dm;

	dm.i = -1;
	dm.s = (int *)ft_calloc(2, sizeof(int));
	dm.e = (int *)ft_calloc(2, sizeof(int));
	dm.color = (unsigned long *)ft_calloc(2, sizeof(unsigned long));
	while (++dm.i < (vars->map->lines - 1))
	{
		dm.j = -1;
		while (++dm.j < (vars->map->rows - 1))
		{
			draw_vert(vars, dm);
			draw_hor(vars, dm);
		}
	}
	ft_printf("draw finished\n");
	free(dm.e);
	free(dm.s);
	free(dm.color);
}

//mlx_pixel_put(mlx, mlx_win, 200 + i, 200 + j, 0xff0000);