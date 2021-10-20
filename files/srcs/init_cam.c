/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:39:16 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/20 12:56:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int select_zoom(int size)
{
	if (size <= 20)
		return (ZOOM);
	else if (size <= 50)
		return (ZOOM / 2);
	else if (size < 150)
		return (ZOOM / 4);
	else
		return (1);
}

s_cam init_cam(fdf *data)
{
	s_cam cam;

	cam.angle = ANGLE1;
	cam.isometric = 1;
	cam.plane = 0;
	cam.zoom = select_zoom(data->map.width);
	cam.pos_x = SIZE_X / 3 + 100;
	cam.pos_y = SIZE_Y / 2;
	return (cam);
}