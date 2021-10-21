/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:23:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/21 11:55:19 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO CONIC

void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ANGLE2);
	*y = (previous_x + previous_y) * sin(ANGLE2) - z;
}

void x_rotation(int *y, int *z, double angle)
{
	int pre_y;
	int pre_z;

	pre_y = *y;
	pre_z = *z;

	*y = pre_y * cos(angle) + pre_z * sin(angle);
	*z = -pre_y * sin(angle) + pre_z * cos(angle);
}

void y_rotation(int *x, int *z, double angle)
{
	int pre_x;
	int pre_z;

	pre_x = *x;
	pre_z = *z;

	*x = pre_x * cos(angle) + pre_z * sin(angle);
	*z = -pre_x * sin(angle) + pre_z * cos(angle);
}

void z_rotation(int *x, int *y, double angle)
{
	int pre_x;
	int pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x * cos(angle) - pre_y * sin(angle);
	*y = pre_x * sin(angle) + pre_y * cos(angle);
}

void rotate(int *x, int *y, int *z, fdf *data)
{
	printf("%f\n", data->cam.angle);
	if (data->cam.rotate[0])
		x_rotation(y, z, data->cam.angle);
	if (data->cam.rotate[1])
		y_rotation(x, z, data->cam.angle);
	if (data->cam.rotate[2])
		z_rotation(x, y, data->cam.angle);
}