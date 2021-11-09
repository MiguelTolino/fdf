/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:27:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 17:42:38 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line_bonus.h"

# define EXT ".fdf"
# define ANGLE1 0.2
# define ANGLE2 0.53
# define SIZE_X 1600
# define SIZE_Y 1200
# define SIZE_CONTROL 200
# define TITLE "FDF"
# define ZOOM 30
# define POSITION 200
# define SPEED_MOV 20

# define RED 0xff0000
# define BLUE 0x0000ff
# define GREEN 0x00ff00
# define WHITE 0xffffff
# define YELLOW 0xffff00
# define PURPLE 0xff00ff
# define AQUAMARINA 0x00ffff

# ifdef __linux__
#  include "../includes/key_linux.h"
#  include "X11/X.h"
# else
#  include "../includes/key_macos.h"
# endif

typedef struct t_lowvars
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;
}	t_lowvars;

typedef struct t_highvars
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	x;
}	t_highvars;

typedef struct t_point
{
	int	x;
	int	y;
}	t_point;

typedef struct t_range
{
	int	max;
	int	min;
	int	range;
}	t_range;

typedef struct t_cam
{
	int		pos_x;
	int		pos_y;
	int		zoom;
	double	angle;
	double	projection_angle;
	int		isometric;
	int		plane;
	int		oblique;
	int		rotate[3];
}	t_cam;

typedef struct t_map
{
	int		**map;
	char	**buffer;
	char	*line;
	int		width;
	int		height;
	int		fd;
	t_range	range;
}	t_map;

typedef struct t_img
{
	void	*ptr;
	int		bbp;
	int		endian;
	int		size_line;
	char	*data;
}	t_img;

typedef struct t_mlx
{
	void			*ptr;
	void			*win;
	t_img			img;
	unsigned int	color;
	int				z_temp;
	int				z1_temp;
}	t_mlx;

typedef struct t_fdf
{
	t_map	map;
	t_mlx	mlx;
	t_cam	cam;
}	t_fdf;

void	check_errors(int argc, char **argv);
t_map	parse_map(char *filename);
int		throw_error(char *error);
int		ft_getnbr(char *str);
int		dfree(char **array);
int		array_length(char **array);
t_mlx	create_window(void);
void	display_img(t_fdf *data);
void	hooks_loop(t_fdf *data);
void	bresenham(t_point p, float x1, float y1, t_fdf *data);
int		free_map(t_map map);
void	plotline(t_point p, int x1, int y1, t_fdf *data);
t_cam	init_cam(t_fdf *data);
t_range	range(t_fdf *data);
void	put_controls(t_mlx mlx);
t_img	create_img(t_mlx mlx);
void	my_mlx_pixel_put(t_fdf *data, int x, int y);
void	new_image(t_fdf *data);
void	end(t_mlx *mlx);
void	iso(int *x, int *y, int z, double angle);
void	rotate(int *x, int *y, int *z, t_fdf *data);
void	perform_zoom(t_point *p0, t_point *p1, int z[], t_fdf *data);
void	perform_position(t_point *p0, t_point *p1, t_fdf *data);
void	test(t_fdf data);

#endif
