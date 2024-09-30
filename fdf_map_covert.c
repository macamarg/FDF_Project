/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_covert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:45 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/30 13:25:12 by macamarg         ###   ########.fr       */
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
			map->x_f = (map->i - map->j) * cosf(STD_ANG);
			map->y_f = (map->i + map->j) * sinf(STD_ANG);
			map->y_f -= map->map_decoded[map->i][map->i];
			map->map_2d[map->i][map->j][0] = map->z_scale * map->x_f + OFFSET_X;
			map->map_2d[map->i][map->j][1] = map->z_scale * map->y_f + OFFSET_Y;
		}
	}
	return (map);
}
