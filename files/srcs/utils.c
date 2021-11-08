/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:56:33 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 14:34:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
