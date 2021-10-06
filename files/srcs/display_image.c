/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/06 13:29:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(s_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->data + (y * img->size_line + x * (img->bbp / 8));
	*(unsigned int *)dst = color;
}

void display_img(s_mlx *mlx)
{
	mlx->img.data = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bbp, &mlx->img.size_line, &mlx->img.endian);
	int x, y;

	x = 0;
	while (x < 200)
	{
		y = 0;
		while (y < 200)
		{
			my_mlx_pixel_put(&mlx->img, x, y, 0x42fd23);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 100, 100);
}