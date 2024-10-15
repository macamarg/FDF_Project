/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:27:31 by macamarg          #+#    #+#             */
/*   Updated: 2024/10/15 14:19:19 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./libft/libft.h"
# include <math.h>

# define HEIGTH 1080
# define WIGTH 1080
# define STD_COLOR 0xf8f8f8
# define CIANO 0x56c7c5
# define LIME_25 0x3bfc41
# define BULE 0x324ccd
# define ORANGE 0xff8b00
# define YELLOW 0xffe957
# define STD_ANG 0.523599
# define X_ANGLE 0.523599
# define Y_ANGLE 0.523599
# define OFFSET_X 400
# define OFFSET_Y 400

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_draw
{
	int				i;
	int				j;
	int				stepx;
	int				stepy;
	int				*s;
	int				*e;
	unsigned long	*color;
	int				dx;
	int				dy;
	int				err;
	int				e2;
	int 			sx;
	int 			sy;
	double			pixels;
}				t_draw;

typedef struct s_map
{
	int				fd;
	char			*line;
	char			**l_spl;
	int				lines;
	int				rows;
	int				**map_decoded;
	unsigned long	***map_color;
	int				i;
	int				j;
	int				z;
	int				z_max;
	int				z_min;
	float			x_max;
	float			x_min;
	float			y_max;
	float			y_min;
	float			x_fit;
	float			y_fit;
	float			***map_2d;
	float			xf;
	float			yf;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				scale;
	int				x_scale;
	int				y_scale;
	float			zoom;
	int				hills;
	float			rotation;
	int				shift;
	int				color_stat;
}					t_map;

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
void	draw_line(t_vars *vars, t_draw dm);
void	draw_hor(t_vars *vars, t_draw dm);
void	draw_vert(t_vars *vars, t_draw dm);
//void	creat_image(t_vars	*vars);

//hooks
int		mouse_hook(int keycode);
int		kill_vars(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

//modify
void	fdf_uphills(t_vars *vars);
void	fdf_downhills(t_vars *vars);
void	fdf_modify(t_vars *vars);
void	fdf_reinit(t_vars *vars);
void	fdf_zoom(t_vars *vars, int factor);
void	fdf_rotate(t_vars *vars, int factor);

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
void	fill_maptab(t_map *map);
int		find_color(char *str);
unsigned long		g_color(char *str);

//convert map into info to draw image
void	*convert_map(t_map	*map);
void	*map_fit(t_map	*map);
void	*range_of_z(t_map	*map);

//freemap
void 	free_map(t_map *map);
void 	free_2d_int(int **arr, int lines);
void 	free_3d_long(unsigned long ***arr, int lines, int rows);
void	free_3d_float(float ***arr, int lines, int rows);

#endif