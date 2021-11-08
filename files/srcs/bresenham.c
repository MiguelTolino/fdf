/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 14:30:27 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	plotlinelow(int x0, int y0, int x1, int y1, t_fdf *data)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;

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
			d = d + 2 * dy;
		x0++;
	}
}

void	plotlinehigh(int x0, int y0, int x1, int y1, t_fdf *data)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	x;

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
			d = d + 2 * dx;
		y0++;
	}
}

void	plotline(int x0, int y0, int x1, int y1, t_fdf *data)
{
	int	z0;
	int	z1;

	z0 = data->map.map[(int)y0][(int)x0];
	z1 = data->map.map[(int)y1][(int)x1];
	x0 *= data->cam.zoom;
	y0 *= data->cam.zoom;
	x1 *= data->cam.zoom;
	y1 *= data->cam.zoom;
	z0 *= data->cam.zoom / 2;
	z1 *= data->cam.zoom / 2;
	iso(&x0, &y0, z0, data->cam.projection_angle);
	iso(&x1, &y1, z1, data->cam.projection_angle);
	x0 += data->cam.pos_x;
	y0 += data->cam.pos_y;
	x1 += data->cam.pos_x;
	y1 += data->cam.pos_y;
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
