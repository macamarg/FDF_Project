/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_covert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:45 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/15 14:24:04 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			map->xf = (map->i - map->j) * cosf(STD_ANG);
			map->yf = (map->i + map->j) * sinf(STD_ANG);
			map->yf -= 0.1 * map->hills * map->map_decoded[map->i][map->j];
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

void	*map_fit(t_map	*map)
{
	map->i = -1;
	map->x_fit = 3 * (WIGTH / (map->x_max - map->x_min)) / 4;
	map->x_fit *= map->rotation;
	map->y_fit = 4 * (HEIGTH / (map->y_max - map->y_min)) / 9;
	while (++map->i < map->lines)
	{
		map->j = -1;
		while (++map->j < map->rows)
		{
			map->map_2d[map->i][map->j][0] *= map->x_fit;
			map->map_2d[map->i][map->j][0] *= map->rotation;
			//map->map_2d[map->i][map->j][0] *= map->zoom;
			map->map_2d[map->i][map->j][0] += WIGTH / 4;
			map->map_2d[map->i][map->j][0] *= map->zoom;
			map->map_2d[map->i][map->j][1] *= map->y_fit;
			//map->map_2d[map->i][map->j][1] *= map->zoom;
			map->map_2d[map->i][map->j][1] += HEIGTH / 4;
			map->map_2d[map->i][map->j][1] *= map->zoom;
		}
	}
	ft_printf("map converted\n");
	return (map);
}
