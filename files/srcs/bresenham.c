/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/17 19:33:10 by mmateo-t         ###   ########.fr       */
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

static void iso(float *x, float *y, int z)
{
    float previous_x;
    float previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
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
	int z0;
	int z1;

	z0 = map.map[(int)y0][(int)x0];
	z1 = map.map[(int)y1][(int)x1];

	x0 *= ZOOM;
	x1 *= ZOOM;
	y0 *= ZOOM;
	y1 *= ZOOM;

	//iso(&x0, &y0, z0);
	//iso(&x1, &y1, z1);

	x_step = x1 - x0;
	y_step = y1 - y0;
	max = MAX(MOD(x_step), MOD(y_step));

	x_step /= max;
	y_step /= max;


	while ((int)(x0 < x1) || (int)(y0 < y1))
	{
		my_mlx_pixel_put(&mlx->img, (int)x0, (int)y0, mlx->color);
		x0 += x_step;
		y0 += y_step;
	}



}