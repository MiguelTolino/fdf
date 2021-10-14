/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/14 13:33:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* void bresenham(int x0, int y0, int x1, int y1, s_mlx *mlx)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dy - dx;
	while (x < x1)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, x, y, GREEN);
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y++;
		}
		x++;
	}
} */

void isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(ANGLE);
	*y = (*x + *y) * sin(ANGLE) - z;
	printf("X: %f \n", *x);
	printf("Y: %f \n", *y);
}

void my_mlx_pixel_put(s_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->data + (y * img->size_line + x * (img->bbp / 8));
	*(unsigned int*)dst = color;
}

void bresenham(float x0, float y0, float x1, float y1, s_mlx *mlx, s_map map)
{
	float x_step;
	float y_step;
	int max;

	//isometric(&x0, &y0, map.map[(int)y0][(int)x0]);
	//isometric(&x1, &y1, map.map[(int)y1][(int)x1]);

	x0 *= ZOOM;
	x1 *= ZOOM;
	y0 *= ZOOM;
	y1 *= ZOOM;


	x_step = x1 - x0;
	y_step = y1 - y0;
	max = MAX(MOD(x_step), MOD(y_step));

	x_step /= max;
	y_step /= max;


	while ((int)(x0 < x1) || (int)(y0 < y1))
	{
		my_mlx_pixel_put(&mlx->img, x0, y0, mlx->color);
		x0 += x_step;
		y0 += y_step;
	}



}