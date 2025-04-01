/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:06:52 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/15 11:37:57 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*free int **map_decoded, int **map color, int *z_range, int **map2d */

void	free_map(t_map *map)
{
	if (map->map_decoded)
	{
		free_2d_int(map->map_decoded, map->lines);
		free_3d_long(map->map_color, map->lines, map->rows);
	}
	if (map->map_2d)
		free_3d_float(map->map_2d, map->lines, map->rows);
}

void	free_2d_int(int **arr, int lines)
{
	int	i;

	i = -1;
	while (++i < lines)
		free (arr[i]);
	free (arr);
}

void	free_3d_long(unsigned long ***arr, int lines, int rows)
{
	int	i;
	int	j;

	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < rows)
			free (arr[i][j]);
		free (arr[i]);
	}
	free (arr);
}

void	free_3d_float(float ***arr, int lines, int rows)
{
	int	i;
	int	j;

	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < rows)
			free (arr[i][j]);
		free (arr[i]);
	}
	free (arr);
}

void	free_arr(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}
