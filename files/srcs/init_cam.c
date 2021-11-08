/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:39:16 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 14:31:46 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	select_zoom(int size)
{
	if (size <= 20)
		return (ZOOM);
	else if (size <= 50)
		return (ZOOM / 2);
	else if (size < 150)
		return (ZOOM / 4);
	else
		return (2);
}

t_cam	init_cam(t_fdf *data)
{
	t_cam	cam;

	data->map.range = range(data);
	cam.angle = 0.1;
	cam.projection_angle = ANGLE2;
	cam.isometric = 1;
	cam.plane = 0;
	cam.oblique = 0;
	cam.zoom = select_zoom(data->map.width);
	cam.pos_x = SIZE_X / 3 + 100;
	cam.pos_y = SIZE_Y / 2;
	cam.rotate[0] = 0;
	cam.rotate[1] = 0;
	cam.rotate[2] = 0;
	return (cam);
}
