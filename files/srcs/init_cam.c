/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:39:16 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 21:16:59 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

s_cam init_cam()
{
	s_cam cam;

	cam.angle = ANGLE1;
	cam.isometric = 1;
	cam.plane = 0;
	cam.zoom = ZOOM;
	cam.pos_x = SIZE_X / 3;
	cam.pos_y = SIZE_Y / 3;
	return (cam);
}