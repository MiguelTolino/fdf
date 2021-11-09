/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:56:33 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 11:10:51 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_range	range(t_fdf *data)
{
	int		x;
	int		y;
	t_range	r;

	y = 0;
	r.max = __INT_MAX__ * -1;
	r.min = __INT_MAX__;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.map[y][x] < r.min)
				r.min = data->map.map[y][x];
			if (data->map.map[y][x] > r.max)
				r.max = data->map.map[y][x];
			x++;
		}
		y++;
	}
	r.range = abs(r.max - r.min);
	return (r);
}

void	perform_zoom(t_point *p0, t_point *p1, int z[2], t_fdf *data)
{
	p0->x *= data->cam.zoom;
	p0->y *= data->cam.zoom;
	p1->x *= data->cam.zoom;
	p1->y *= data->cam.zoom;
	z[0] *= data->cam.zoom / 2;
	z[1] *= data->cam.zoom / 2;
}

void	perform_position(t_point *p0, t_point *p1, t_fdf *data)
{
	p0->x += data->cam.pos_x;
	p0->y += data->cam.pos_y;
	p1->x += data->cam.pos_x;
	p1->y += data->cam.pos_y;
}

void	hooks_perspective(t_fdf *data, int keycode)
{
	if (keycode == K_I)
	{
		data->cam.isometric = 1;
		data->cam.plane = 0;
		data->cam.oblique = 0;
		data->cam.projection_angle = ANGLE2;
	}
	if (keycode == K_P)
	{
		data->cam.plane = 1;
		data->cam.isometric = 0;
		data->cam.oblique = 0;
	}
	if (keycode == K_O)
	{
		data->cam.plane = 0;
		data->cam.isometric = 0;
		data->cam.oblique = 1;
		data->cam.projection_angle = ANGLE1;
	}
}
