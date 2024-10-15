/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:37 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/15 13:56:47 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_info(char c)
{
	int	info;

	info = 0;
	if (44 <= c && c <= 122)
		info = 1;
	return (info);
}

int	fdf_word_count(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		while (44 <= line[i] && line[i] <= 122)
			i++;
		i++;
		count++;
	}
	return (count);
}

int	fdf_check_format(t_map *map, int fd)
{
	int	row_conf;

	ft_printf("map check\n\n");
	map->line = get_next_line(fd);
	while (map->line != NULL)
	{
		row_conf = fdf_word_count(map->line);
		if (map->lines == 0)
			map->rows = row_conf;
		else if (map->rows != row_conf)
		{
			free(map->line);
			return (0);
		}
		map->lines++;
		free (map->line);
		map->line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	fill_maptab(t_map *map)
{
	while (++map->i < map->lines)
	{
		map->line = get_next_line (map->fd);
		map->map_decoded[map->i] = (int *)ft_calloc(map->rows, sizeof(int *));
		map->map_color[map->i] = ft_calloc(map->rows, sizeof(unsigned long *));
		map->j = -1;
		map->l_spl = ft_split (map->line, ' ');
		while (++map->j < map->rows && map->l_spl[map->j] != NULL)
		{
			map->map_decoded[map->i][map->j] = ft_atoi (map->l_spl[map->j]);
			map->map_color[map->i][map->j] = ft_calloc(2,
					sizeof(unsigned long **));
			map->map_color[map->i][map->j][0] = find_color(map->l_spl[map->j]);
			if (map->map_color[map->i][map->j][0] == 1)
				map->map_color[map->i][map->j][1] = g_color(map->l_spl[map->j]);
			else
				map->map_color[map->i][map->j][1] = STD_COLOR;
			if (map->map_decoded[map->i][map->j] > map->z_max)
				map->z_max = map->map_decoded[map->i][map->j];
			if (map->map_decoded[map->i][map->j] < map->z_min)
				map->z_min = map->map_decoded[map->i][map->j];
		}
		free_arr (map->l_spl, map->rows - 1);
		free (map->line);
	}
}

t_map	*get_map(t_map *map, int fd, char *map_file)
{
	if (fdf_check_format(map, fd) == 0)
	{
		if (map)
			free(map);
		close(fd);
		fdf_exit("Map in the wrong format\n", 5);
	}
	ft_printf("map checked\n");
	map->map_decoded = (int **)ft_calloc(map->lines, sizeof(int *));
	map->map_color = ft_calloc(map->lines, sizeof(unsigned long *));
	map->fd = open (map_file, O_RDONLY);
	fill_maptab (map);
	close (map->fd);
	map->scale = (map->z_max - map->z_min);
	map->x_scale = (100 * map->lines) / WIGTH;
	map->y_scale = (100 * map->rows) / HEIGTH;
	convert_map(map);
	map_fit(map);
	return (map);
}
