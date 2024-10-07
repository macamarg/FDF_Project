/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_covert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:45 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/02 14:52:51 by macamarg         ###   ########.fr       */
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
			//ft_printf("\n%i %i \n", map->i, map->j);
			map->map_2d[map->i][map->j] = ft_calloc(2, sizeof(float));
			map->xf = (map->i - map->j) * cosf(STD_ANG);
			map->yf = (map->i + map->j) * sinf(STD_ANG);
			map->yf -= map->map_decoded[map->i][map->j];
			//printf("%f %f %i\n", map->x_f, map->y_f, map->z_scale);
			map->map_2d[map->i][map->j][0] = (3*map->scale * map->xf) + OFFSET_X;
			map->map_2d[map->i][map->j][1] = (3 *map->scale * map->yf) + OFFSET_Y;
			//printf("%f %f  ", map->map_2d[map->i][map->j][0], map->map_2d[map->i][map->j][1]);fflush(stdout);		
		}
		//ft_printf("\n");
	}
	ft_printf("map converted\n");
	return (map);
}
