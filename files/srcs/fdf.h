/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:27:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/07 09:58:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
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
#define K 0.82

#define SIZE_X 500
#define SIZE_Y 500
#define TITLE "FDF"

typedef struct s_map
{
	int **map;
	char **buffer;
	char *line;
	int x;
	int *y;
	int fd;
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
}	s_mlx;




void check_errors(int argc, char **argv);
s_map parse_map(char *filename);
int	throw_error(char *error);
int	ft_getnbr(char *str);
int dfree(char **array);
int array_length(char **array);
s_mlx create_window();
void display_img(s_mlx *mlx);
void hooks_loop(s_mlx mlx);

#endif
