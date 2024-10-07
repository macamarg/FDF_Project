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

void	draw_line(t_vars *vars, int *s, int *e)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int sx = s[0] < e[0] ? 1 : -1;
	int sy = s[0] < e[0] ? 1 : -1;

	dx = abs(e[0] - s[0]);
	dy = -abs(e[1] - s[1]);
	err = dx + dy;
	while (1)
    {
        my_mlx_pixel_put(&vars->img, 1000 - s[0], s[1], 0xFFFFFF);
        if (s[0] == e[0] && s[1] == e[1])
            break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; s[0] += sx; }
        if (e2 <= dx) { err += dx; s[1] += sy; }
    }
}

void	fdf_mapdraw(t_vars *vars)
{
	int		i;
	int		j;
	int		*s;
	int		*e;
	//unsigned long	*color;

	i = -1;
	s = (int *)ft_calloc(2, sizeof(int));
	e = (int *)ft_calloc(2, sizeof(int));
	//color = (unsigned long *)ft_calloc(2, sizeof(unsigned long));
	while (++i < (vars->map->lines - 1))
	{
		j = -1;
		while (++j < (vars->map->rows - 1))
		{
			s[0] = vars->map->map_2d[i][j][0];
			s[1] = vars->map->map_2d[i][j][1];
			e[0] = vars->map->map_2d[i + 1 ][j + 1][0];
			e[1] = vars->map->map_2d[i + 1 ][j + 1][0];
			//color[0] = vars->map->map_color[i][j];
			//color[0] = vars->map->map_color[i + 1 ][j + 1];
			my_mlx_pixel_put(&vars->img, 900 -s[0], s[1], 0xff0000);
		}
	}
	free(e);
	free(s);
	//free(color);
}

//mlx_pixel_put(mlx, mlx_win, 200 + i, 200 + j, 0xff0000);