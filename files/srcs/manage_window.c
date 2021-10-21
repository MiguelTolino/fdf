/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:40:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/21 00:19:05 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void end(s_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(EXIT_SUCCESS);
}

void new_image(fdf *data)
{
	mlx_destroy_image(data->mlx.ptr, data->mlx.img.ptr);
	data->mlx.img = create_img(data->mlx);
	display_img(data);
}

void put_controls(s_mlx mlx)
{
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 50, 0xffffff, "CONTROLS");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 55, 0x00ff00, "________");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 80, 0xffffff, "Zoom: Scroll");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 100, 0xffffff, "Move");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 105, 0x00ff00, "____");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 130, 0xffffff, "W -> Up");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 150, 0xffffff, "S -> Down");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 170, 0xffffff, "A -> Left");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 190, 0xffffff, "D -> Right");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 220, 0xffffff, "Projection:");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 225, 0x00ff00, "___________");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 250, 0xffffff, "ISO -> I");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 270, 0xffffff, "PLANE -> P");
}

s_img create_img(s_mlx mlx)
{
	s_img img;

	if (!(img.ptr = mlx_new_image(mlx.ptr, SIZE_X, SIZE_Y)) ||
		!(img.data = mlx_get_data_addr(img.ptr, &img.bbp, &img.size_line, &img.endian)))
		throw_error("Minilibx Error");
	return (img);
}

s_mlx create_window()
{
	s_mlx mlx;

	if (!(mlx.ptr = mlx_init()) ||
		!(mlx.win = mlx_new_window(mlx.ptr, SIZE_X, SIZE_Y, TITLE)))
		throw_error("Minilibx Error");
	mlx.img = create_img(mlx);
	return (mlx);
}