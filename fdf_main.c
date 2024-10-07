/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:26:43 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/02 14:53:16 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf(int fd, char *map_file)
{
	t_vars	vars;
	

	ft_printf("fdf function\n");
	vars.map = malloc(sizeof(t_map));
	if (!vars.map)
		fdf_exit("Fail to allocate map\n", 4);
	initiate_map(vars.map);
	vars.map = get_map(vars.map, fd, map_file);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIGTH, HEIGTH, "FDF");
	vars.img.img = mlx_new_image(vars.mlx, WIGTH, HEIGTH);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	fdf_mapdraw(&vars);
	// int i = 100;
	// int	j = 100;
	// while(i < 200)
	// {
	// 	//mlx_pixel_put(mlx, mlx_win, 200 + i, 200 + j, 0xff0000);
	// 	my_mlx_pixel_put(&vars.img, i, j, 0xff0000);
	// 	my_mlx_pixel_put(&vars.img, 200+i, j, 0x00ffff);
	// 	my_mlx_pixel_put(&vars.img, i, 200+j, 0x0000ff);
	// 	j++;
	// 	i++;
	// }
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);//pq 0, 0??
	mlx_hook(vars.win, 17, 0, kill_vars, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}

void initiate_map(t_map *map)
{
	map->line = NULL;
	map->lines = 0;
	map->i = -1;
	map->z_max = 0;
	map->z_min = 0;
	map->zoom = 1;
	
}

int	check_mapextension(char *map_file)
{
	int	i;

	i = 0;
	while (map_file[i])
	{
		if (map_file[i] == '.')
		{
			if (ft_strncmp(&map_file[i], ".fdf", 4) == 0 && !map_file[i + 4])
				return (1);
		}
		i++;
	}
	return (0);
}

int	fdf_exit(char *msg, int n_error)
{
	ft_putstr_fd (msg, 2);
	exit (n_error);
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

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		if (check_mapextension (argv[1]) == 0)
			fdf_exit ("Wrong file extension\n", 2);
		fd = open (argv[1], O_RDONLY);
		if ((fd <= 0))
			fdf_exit ("Error openning file\n", 3);
		else
		{
			ft_printf("call fdf\n");
			ft_fdf (fd, argv[1]);
		}
	}
	else
		fdf_exit ("run like ./fdf <map name>.fdf\n", 1);
}
