/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/18 23:30:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

float maxi(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static void iso(float *x, float *y, int z)
{
    float previous_x;
    float previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.53);
    *y = (previous_x + previous_y) * sin(0.53) - z;
}
void my_mlx_pixel_put(fdf *data, int x, int y)
{
	char *dst;

	dst = data->mlx.img.data + (y * data->mlx.img.size_line + x * (data->mlx.img.bbp / 8));
	*(unsigned int*)dst = data->mlx.color;
}

void bresenham(float x0, float y0, float x1, float y1, fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z0;
	int z1;

	z0 = data->map.map[(int)y0][(int)x0];
	z1 = data->map.map[(int)y1][(int)x1];

 	iso(&x0, &y0, z0);
	iso(&x1, &y1, z1);

	x0 *= ZOOM;
	x1 *= ZOOM;
	y0 *= ZOOM;
	y1 *= ZOOM;


 	x0 += POSITION;
	x1 += POSITION;
	y0 += POSITION;
	y1 += POSITION;


	x_step = x1 - x0;
	y_step = y1 - y0;
	max = MAX(MOD(x_step), MOD(y_step));

	x_step /= max;
	y_step /= max;
	while ((int)(x0 < x1) || (int)(y0 < y1))
	{
		if (x0 >= SIZE_X || y0 >= SIZE_Y || x0 < 0 || y0 < 0)
			break;
		my_mlx_pixel_put(data, (int)x0, (int)y0);
		x0 += x_step;
		y0 += y_step;
	}



}