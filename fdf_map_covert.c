

#include "fdf.h"


void	*convert_map(t_map	*map)
{
	ft_printf("map convert\n");fflush(stdout);
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
			map->map_2d[map->i][map->j][0] = 25 * map->x_f + OFFSET_X;
			map->map_2d[map->i][map->j][1] = 25 * map->y_f + OFFSET_Y;
		}
	}
	return (map);
}