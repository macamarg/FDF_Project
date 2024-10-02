/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:37 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/02 14:51:12 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_info(char c)
{
	int	info;

	info = 0;
	if ('0' <= c && c <= '9')
		info = 1;
	else if (('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'))
		info = 1;
	else if (c == '-' || c == ',' || c == 'x' || c == 'X')
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
		while (is_info (line[i]) == 1)
			i++;
		while (line[i] == ' ' || line[i] == '\n')
			i++;
		count++;
	}
	return (count);
}

int	fdf_check_format(t_map *map, int fd)
{
	int	row_conf;

	ft_printf("map check\n\n");fflush(stdout);
	map->line = get_next_line(fd);
	while (map->line != NULL)
	{
		ft_printf("%i %s\n", map->lines, map->line);
		row_conf = fdf_word_count(map->line);
		if (map->lines == 0)
			map->rows = row_conf;
		else if (map->rows != row_conf)
			return (0);
		map->lines++;
		free(map->line);
		map->line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	fill_maptap(t_map *map)
{
	while (++map->i < map->lines)
	{
		map->line = get_next_line (map->fd);
		map->map_decoded[map->i] = (int *)ft_calloc(map->rows, sizeof(int *));
		map->map_color[map->i] = (int *)ft_calloc(map->rows, sizeof(int *));
		map->j = -1;
		map->line_spl = ft_split (map->line, ' ');
		while (++map->j < map->rows)
		{
			map->map_decoded[map->i][map->j] = ft_atoi (map->line_spl[map->j]);
			//map->map_color[map->i][map->j] = ft_atoi (map->line_spl[map->j]);
			if (find_color(map->line_spl[map->j]) == 1)
				map->map_color[map->i][map->j] = g_color(map->line_spl[map->j]);
			else
				map->map_color[map->i][map->j] = SDT_COLOR;
			if (map->map_decoded[map->i][map->j] > map->z_max)
				map->z_max = map->map_decoded[map->i][map->j];
			if (map->map_decoded[map->i][map->j] < map->z_min)
				map->z_min = map->map_decoded[map->i][map->j];
		}
		free_arr (map->line_spl, map->rows - 1);
		free (map->line);
	}
}

t_map	*get_map(t_map *map, int fd, char *map_file)
{
	map->line = NULL;
	ft_printf("line %s\n", map->line);
	if (fdf_check_format(map, fd) == 0)
	{
		if (map)
			free(map);
		close(fd);
		fdf_exit("Map in the wrong format\n", 5);
	}
	ft_printf("map checked\n");
	map->map_decoded = (int **)ft_calloc(map->lines, sizeof(int *));
	map->map_color = (int **)ft_calloc(map->lines, sizeof(int *));
	map->fd = open (map_file, O_RDONLY);
	fill_maptap (map);
	close (map->fd);
	map->z_max = map->z_max - map->z_min;
	convert_map(map);
	return (map);
}
