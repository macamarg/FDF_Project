/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:26:43 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/25 15:29:00 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_function (int fd, char *map_file)
{
	t_vars	vars;

	vars.map = fdf_get_map(vars.map, fd, map_file);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIGTH, HEIGTH, "FDF");
	vars.img.img = mlx_new_image(vars.mlx, WIGTH, HEIGTH);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);//pq 0, 0??
	mlx_hook(vars.win, 17, 0, kill_vars, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}


int	main(int argc, char **argv)
{
	int	fd;
	if (argc == 2)
	{
		if (open(argv[1], O_RDONLY) == -1)
		{
			write (2, "error openning file\n", 20);
			exit (2);
		}
		else
			fdf_function(fd, argv[1]);
	}
	else
	{
		write (2, "run like ./fdf <map name>.fdf\n", 30);
		exit (1);
	}
}
