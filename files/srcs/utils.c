/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:56:33 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/20 16:54:07 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

s_range range(fdf *data)
{
	int x;
	int y;
	s_range r;

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

//TODO: ROTATE
//FIXME: FIX ROTATION

void x_rotation(int *x, int *y)
{
	int pre_y;
	int pre_x;

	pre_x = *x;
	pre_y = *y;

	*x = pre_x * cos(ANGLE2) + pre_y * sin(ANGLE2);
	*y = -pre_x * sin(ANGLE2) + pre_y * cos(ANGLE2);
}

void y_rotation(int *x, int *y)
{
	int pre_y;
	int pre_x;

	pre_x = *x;
	pre_y = *y;

	*x = pre_x * cos(ANGLE2) - pre_y * sin(ANGLE2);
	*y = pre_x * sin(ANGLE2) + pre_y * cos(ANGLE2);
}