/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 19:01:06 by mmateo-t         ###   ########.fr       */
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

static void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.53);
	*y = (previous_x + previous_y) * sin(0.53) - z;

}
void my_mlx_pixel_put(fdf *data, int x, int y)
{
	char *dst;

	if (x >= SIZE_X || x < 0 || y>= SIZE_Y || y < 0)
		return;
	dst = data->mlx.img.data + (y * data->mlx.img.size_line + x * (data->mlx.img.bbp / 8));
	*(unsigned int *)dst = data->mlx.color;
}

/* void bresenham(float x0, float y0, float x1, float y1, fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z0;
	int z1;

	z0 = data->map.map[(int)y0][(int)x0];
	z1 = data->map.map[(int)y1][(int)x1];

	//iso(&x1, &y1, z1);
	//iso(&x0, &y0, z0);

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
	max = maxi(mod(x_step), mod(y_step));

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
} */

void plotlinelow(int x0,int  y0,int  x1,int y1, fdf *data)
{
	int dx;
	int dy;
	int yi;
	int d;
	int y;

    dx = x1 - x0;
    dy = y1 - y0;
    yi = 1;
    if (dy < 0)
	{
        yi = -1;
        dy = -dy;
	}
    d = (2 * dy) - dx;
    y = y0;
    while (x0 < x1)
	{
        my_mlx_pixel_put(data, x0, y);
        if (d > 0)
		{
            y = y + yi;
            d = d + (2 * (dy - dx));
		}
        else
            d = d + 2*dy;
		x0++;
	}
}

void plotlinehigh(int x0, int y0, int x1, int y1, fdf *data)
{
	int dx;
	int dy;
	int xi;
	int d;
	int x;

	dx = x1 - x0;
    dy = y1 - y0;
    xi = 1;
    if (dx < 0)
	{
        xi = -1;
        dx = -dx;
	}
    d = (2 * dx) - dy;
    x = x0;
  while (y0 < y1)
  {
	  my_mlx_pixel_put(data, x, y0);
        if (d > 0)
		{
            x = x + xi;
            d = d + (2 * (dx - dy));
		}
        else
            d = d + 2*dx;
		y0++;
  }
}

void plotline(int x0, int y0, int x1, int y1, fdf *data)
{
	int z0;
	int z1;


	z0 = data->map.map[(int)y0][(int)x0];
	z1 = data->map.map[(int)y1][(int)x1];
 	x0 *= ZOOM;
	y0 *= ZOOM;
	x1 *= ZOOM;
	y1 *= ZOOM;
	z0 *= ZOOM;
	z1 *= ZOOM;

	iso(&x0, &y0, z0);
	iso(&x1, &y1, z1);


	x0 += POSITION;
	y0 += POSITION;
	x1 += POSITION;
	y1 += POSITION;



    if (abs(y1 - y0) < abs(x1 - x0))
	{
        if (x0 > x1)
            plotlinelow(x1, y1, x0, y0, data);
        else
            plotlinelow(x0, y0, x1, y1, data);
	}
    else
	{
        if (y0 > y1)
            plotlinehigh(x1, y1, x0, y0, data);
        else
            plotlinehigh(x0, y0, x1, y1, data);
	}
}