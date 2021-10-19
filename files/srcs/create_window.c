/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:40:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 20:28:16 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_controls(s_mlx mlx)
{
	// 200x800
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 50, 0xffffff, "CONTROLS");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 55, 0xffffff, "________");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 80, 0xffffff, "ZOOM: Scroll");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 100, 0xffffff, "MOVE: Arrows");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL / 4, 120, 0xffffff, "Projection: ISO -> I");
}

s_img create_img(s_mlx mlx)
{
	s_img img;

	img.ptr = mlx_new_image(mlx.ptr, SIZE_X, SIZE_Y);
	img.data = mlx_get_data_addr(img.ptr, &img.bbp, &img.size_line, &img.endian);
	ft_bzero(img.data, ft_strlen(img.data));
	return (img);
}

s_mlx create_window()
{
	s_mlx mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, SIZE_X, SIZE_Y, TITLE);
	mlx.img = create_img(mlx);
	return (mlx);
}