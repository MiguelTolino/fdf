/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:46:19 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 17:41:35 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	test(t_fdf data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	printf("W:%i\n", data.map.width);
	printf("H:%i\n", data.map.height);
	printf("R:%i\n", data.map.range.range);
	while (y < data.map.height)
	{
		x = 0;
		while (x < data.map.width)
		{
			printf("%3i", data.map.map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	exit(1);
}
