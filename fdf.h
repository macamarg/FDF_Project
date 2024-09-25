/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamarg <macamarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:27:31 by macamarg          #+#    #+#             */
/*   Updated: 2024/09/25 14:50:36 by macamarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./minilibx-linux/mlx.h"
#include "./minilibx-linux/mlx_int.h"
#include "./libft/libft.h"
#include <math.h>

#define HEIGTH 1000
#define WIGTH 1000


typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef	struct s_map
{
	int			fd;
	char		*line;
	char		**line_spl;
	int			line_count;
	int			row_n;
	int			**map_decoded;
	int			**map_color;
	int			i;
	int			j;
	int			z;
	int			*range_z;//0 = min, 1 = max
	float		***map_2d;
	float		x_f;
	float		y_f;
	int			*z_scale;
}				t_map;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_map		*map;
}				t_vars;

//image
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned long color);
//void	creat_image(t_vars	*vars);


//hooks
int		mouse_hook(int keycode);
int		kill_vars(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

//maps
int		is_info(char c);
int		fdf_word_count(char *line);
void	*map_line_count(t_map *map, char *map_addr);
void	free_arr(char **array, int i);
void 	*get_map(t_map *map, char *map_addr);
int		find_color(char *str);
int		g_color(char *str);
void	*convert_map(t_map	*map);
void	*range_of_z(t_map	*map);



#endif