/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:56:33 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 19:56:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int range(fdf *data)
{
	int x;
	int y;
	int max;
	int min;

	y = 0;
	max = __INT_MAX__ * -1;
	min = __INT_MAX__;
	while (y < data->map.height)
	{
		x = 0;
 		while (x < data->map.width)
		{
			if (data->map.map[y][x] < min)
				min = data->map.map[y][x];
			if (data->map.map[y][x] > max)
				max = data->map.map[y][x];
			x++;
		}
		y++;
	}
	return (abs(max - min));
}