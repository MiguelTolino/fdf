/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 00:03:39 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define N_COLORS 6

unsigned int	set_color(int x, int y, t_map map, t_range r)
{
	int		z;
	float	inc;

	z = map.map[y][x];
	inc = (float)r.range / N_COLORS;
	if (z <= r.min + inc)
		return (WHITE);
	else if (z <= (r.min + 2 * inc))
		return (YELLOW);
	else if (z <= (r.min + 3 * inc))
		return (BLUE);
	else if (z <= (r.min + 4 * inc))
		return (GREEN);
	else if (z <= (r.min + 5 * inc))
		return (PURPLE);
	else if (z <= (r.min + 6 * inc))
		return (RED);
	return (0);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y)
{
	char	*dst;

	if (x >= SIZE_X || x < 0 || y >= SIZE_Y || y < 0)
		return ;
	dst = data->mlx.img.data + (y * data->mlx.img.size_line
			+ x * (data->mlx.img.bbp / 8));
	*(unsigned int *)dst = data->mlx.color;
}

void	display_img(t_fdf *data)
{
	t_point	p;

	p.y = 0;
	while (p.y < data->map.height)
	{
		p.x = 0;
		while (p.x < data->map.width)
		{
			data->mlx.color = set_color(p.x, p.y, data->map, data->map.range);
			if (p.x < data->map.width - 1)
				plotline(p, p.x + 1, p.y, data);
			if (p.y < data->map.height - 1)
				plotline(p, p.x, p.y + 1, data);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
		data->mlx.img.ptr, 0, 0);
}
