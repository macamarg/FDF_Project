/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_covert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:45 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/25 11:22:23 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf_bonus.h"

void	*convert_map(t_map	*map)
{
	map->map_2d = (float ***)ft_calloc(map->lines, sizeof(float **));
	map->i = -1;
	while (++map->i < map->lines)
	{
		map->map_2d[map->i] = ft_calloc(map->rows, sizeof(float *));
		map->j = -1;
		while (++map->j < map->rows)
		{
			map->map_2d[map->i][map->j] = ft_calloc(2, sizeof(float));
			map->xf = (map->i - map->j) * cosf(STD_ANG * map->rotation_x);
			map->yf = (map->i + map->j) * sinf(STD_ANG * map->rotation_y);
			map->yf -= 0.12 * map->hills * map->map_decoded[map->i][map->j];
			if (map->x_max <= map->xf)
				map->x_max = map->xf;
			if (map->x_min >= map->xf)
				map->x_min = map->xf;
			if (map->y_max <= map->yf)
				map->y_max = map->yf;
			if (map->y_min >= map->yf)
				map->y_min = map->yf;
			map->map_2d[map->i][map->j][0] = map->xf;
			map->map_2d[map->i][map->j][1] = map->yf;
		}
	}
	return (map);
}

void	map_fit(t_map	*map)
{
	float	angle;

	map->i = -1;
	angle = map->rotation * ROT_ANGLE;
	while (++map->i < map->lines)
	{
		map->j = -1;
		while (++map->j < map->rows)
		{
			map->xf = map->zoom * map->map_2d[map->i][map->j][0];
			map->yf = map->zoom * map->map_2d[map->i][map->j][1];
			
			
			map->x_rotated = map->xf * cosf(angle) - map->yf * sinf(angle);
			map->y_rotated = map->xf * sinf(angle) + map->yf * cosf(angle);
			// map->x_rotated -= map->d_x;
			// map->y_rotated -= map->d_y;
			// map->x_rotated += map->shift_x * WIGTH / 2;
			// map->y_rotated += map->shift_y * HEIGTH / 2;
			
			map->x_rotated *= map->x_fit;
			map->y_rotated *= map->y_fit;
			map->x_rotated -= map->d_x;
			map->y_rotated -= map->d_y;
			map->x_rotated += map->shift_x * WIGTH * 0.33;
			map->y_rotated += map->shift_y * HEIGTH * 0.33;
			map->map_2d[map->i][map->j][0] = map->x_rotated;
			map->map_2d[map->i][map->j][1] = map->y_rotated;
		}
	}
}

/* 
void	map_fit(t_map	*map)
{
	float	angle;

	map->i = -1;
	angle = map->rotation * ROT_ANGLE;
	while (++map->i < map->lines)
	{
		map->j = -1;
		while (++map->j < map->rows)
		{
			map->xf = map->zoom * map->map_2d[map->i][map->j][0];
			map->yf = map->zoom * map->map_2d[map->i][map->j][1];
			map->x_rotated = map->xf * cosf(angle) - map->yf * sinf(angle);
			map->y_rotated = map->xf * sinf(angle) + map->yf * cosf(angle);
			map->x_rotated *= map->x_fit;
			map->y_rotated *= map->y_fit;
			map->x_rotated -= map->d_x;
			map->y_rotated -= map->d_y;
			map->x_rotated += map->shift_x * WIGTH / 2;
			map->y_rotated += map->shift_y * HEIGTH / 2;
			map->map_2d[map->i][map->j][0] = map->x_rotated;
			map->map_2d[map->i][map->j][1] = map->y_rotated;
		}
	}
} */


