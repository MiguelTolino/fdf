/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:18:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 10:03:08 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	plotlinelow(t_point p0, t_point p1, t_fdf *data)
{
	t_lowvars	v;

	v.dx = p1.x - p0.x;
	v.dy = p1.y - p0.y;
	v.yi = 1;
	if (v.dy < 0)
	{
		v.yi = -1;
		v.dy = -v.dy;
	}
	v.d = (2 * v.dy) - v.dx;
	v.y = p0.y;
	while (p0.x < p1.x)
	{
		my_mlx_pixel_put(data, p0.x, v.y);
		if (v.d > 0)
		{
			v.y = v.y + v.yi;
			v.d = v.d + (2 * (v.dy - v.dx));
		}
		else
			v.d = v.d + 2 * v.dy;
		p0.x++;
	}
}

void	plotlinehigh(t_point p0, t_point p1, t_fdf *data)
{
	t_highvars	v;

	v.dx = p1.x - p0.x;
	v.dy = p1.y - p0.y;
	v.xi = 1;
	if (v.dx < 0)
	{
		v.xi = -1;
		v.dx = -v.dx;
	}
	v.d = (2 * v.dx) - v.dy;
	v.x = p0.x;
	while (p0.y < p1.y)
	{
		my_mlx_pixel_put(data, v.x, p0.y);
		if (v.d > 0)
		{
			v.x = v.x + v.xi;
			v.d = v.d + (2 * (v.dx - v.dy));
		}
		else
			v.d = v.d + 2 * v.dx;
		p0.y++;
	}
}

void	plotline(t_point p0, int x1, int y1, t_fdf *data)
{
	int		z[2];
	t_point	p1;

	p1.x = x1;
	p1.y = y1;
	z[0] = data->map.map[(int)p0.y][(int)p0.x];
	z[1] = data->map.map[(int)p1.y][(int)p1.x];
	perform_zoom(&p0, &p1, z, data);
	iso(&p0.x, &p0.y, z[0], data->cam.projection_angle);
	iso(&p1.x, &p1.y, z[1], data->cam.projection_angle);
	perform_position(&p0, &p1, data);
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			plotlinelow(p1, p0, data);
		else
			plotlinelow(p0, p1, data);
	}
	else
	{
		if (p0.y > p1.y)
			plotlinehigh(p1, p0, data);
		else
			plotlinehigh(p0, p1, data);
	}
}
