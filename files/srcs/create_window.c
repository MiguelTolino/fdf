/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:40:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/14 14:51:21 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

s_img create_img(s_mlx mlx)
{
	s_img img;

	img.ptr = mlx_new_image(mlx.ptr, SIZE_X, SIZE_Y);
	img.data = mlx_get_data_addr(img.ptr, &img.bbp, &img.size_line, &img.endian);
	return (img);
}

s_mlx create_window()
{
	s_mlx mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, SIZE_X, SIZE_Y, TITLE);
	mlx.img = create_img(mlx);
	return(mlx);
}