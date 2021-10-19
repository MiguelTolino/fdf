/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:27:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 19:02:23 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "X11/X.h"
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line_bonus.h"
#include "../includes/key_linux.h"

#define EXT ".fdf"
#define ANGLE 0.82

#define SIZE_X 1000
#define SIZE_Y 1000
#define TITLE "FDF"
#define ZOOM 20
#define POSITION 200
#define MAX(a,b) (a > b ? a : b)
#define MOD(a) (a < 0 ? a * -1 : a)

#define RED 0xff0000
#define BLUE 0x0000ff
#define GREEN 0x00ff00
#define WHITE 0xffffff
#define YELLOW 0xffff00
#define PURPLE 0xff00ff
#define AQUAMARINA 0x00ffff

typedef struct s_step
{
	int x;
	int *y;
} s_step;

typedef struct s_map
{
	int **map;
	char **buffer;
	char *line;
	int width;
	int height;
	int fd;
	s_step step;
} s_map;

typedef struct s_img
{
	void *ptr;
	int bbp;
	int endian;
	int size_line;
	char *data;
}	s_img;

typedef struct s_mlx
{
	void *ptr;
	void *win;
	s_img img;
	unsigned int color;
	int z_temp;
	int z1_temp;
}	s_mlx;

typedef struct fdf
{
	s_map map;
	s_mlx mlx;
}	fdf;

void check_errors(int argc, char **argv);
s_map parse_map(char *filename);
int	throw_error(char *error);
int	ft_getnbr(char *str);
int dfree(char **array);
int array_length(char **array);
s_mlx create_window();
void display_img(fdf *data);
void hooks_loop(s_mlx mlx);
void bresenham(float x0, float y0, float x1, float y1, fdf *data);
int free_map(s_map map);
void plotline(int x0, int y0, int x1, int y1, fdf *data);

#endif
