/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_covert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:45 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/07 15:20:16 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*convert_map(t_map	*map)
{
	ft_printf ("map convert\n");
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
			map->yf -= 0.1 *map->map_decoded[map->i][map->j];
			map->map_2d[map->i][map->j][0] = (3 * map->x_scale * map->scale * map->xf) + OFFSET_X;
			map->map_2d[map->i][map->j][1] = (4 * map->y_scale * map->scale * map->yf) + OFFSET_Y;
		}
	}
	ft_printf("map converted\n");
	return (map);
}
