/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:27:31 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/02 11:46:02 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../minilibx-linux/mlx.h"
# include "../../minilibx-linux/mlx_int.h"
# include "./libft/libft.h"
# include <math.h>

# define HEIGTH 1000
# define WIGTH 1000
# define SDT_COLOR 0xf8f8f8
# define CIANO 0x56c7c5
# define LIME_25 0x3bfc41
# define BULE 0x324ccd
# define ORANGE 0xff8b00
# define YELLOW 0xffe957
# define STD_ANG 0.523599
# define X_ANGLE 0.523599
# define Y_ANGLE 0.523599
# define OFFSET_X 500
# define OFFSET_Y 500

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		**line_spl;
	int			lines;
	int			rows;
	int			**map_decoded;
	int			**map_color;
	int			i;
	int			j;
	int			z;
	int			z_max;
	int			z_min;
	float		***map_2d;
	float		x_f;
	float		y_f;
	int			z_scale;
	int			zoom;
	int			rotation;
	int			shift;
}				t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_map		*map;
}				t_vars;

//image
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned long color);
void	fdf_mapdraw(t_vars *vars);
//void	creat_image(t_vars	*vars);

//hooks
int		mouse_hook(int keycode);
int		kill_vars(t_vars vars);
int		key_hook(int keycode, t_vars vars);

//main
void	ft_fdf(int fd, char *map_file);
int		check_mapextension(char *map_file);
int		fdf_exit(char *msg, int n_error);
void	free_arr(char **array, int i);
void	 initiate_map(t_map *map);

//maps
t_map	*get_map(t_map *map, int fd, char *map_file);
int		fdf_word_count(char *line);
int		fdf_check_format(t_map *map, int fd);
int		is_info(char c);
void	fill_maptap(t_map *map);
int		find_color(char *str);
int		g_color(char *str);

//convert map into info to draw image
void	*convert_map(t_map	*map);
void	*range_of_z(t_map	*map);

//freemap
void 	free_map(t_map *map);
void 	free_2d_int(int **arr, int lines);
void	 free_3d_float(float ***arr, int lines, int rows);

#endif