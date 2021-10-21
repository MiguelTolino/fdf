/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:40:36 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/21 13:52:49 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rotation(int keycode, fdf *data)
{
	if (keycode == KEY_LEFT)
		data->cam.rotate[0] = 1;
	if (keycode == KEY_RIGHT)
		data->cam.rotate[1] = 1;
	if (keycode == KEY_UP)
		data->cam.rotate[2] = 1;
	if (keycode == KEY_DOWN)
	{
		data->cam.rotate[0] = 0;
		data->cam.rotate[1] = 0;
		data->cam.rotate[2] = 0;
		data->cam.angle = 0;
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP)
		data->cam.angle += 0.1;
}

int key_action(int keycode, fdf *data)
{
	if (keycode == KEY_ESC)
		end(&data->mlx);
	if (keycode == KEY_W)
		data->cam.pos_y -= 10;
	if (keycode == KEY_A)
		data->cam.pos_x -= 10;
	if (keycode == KEY_D)
		data->cam.pos_x += 10;
	if (keycode == KEY_S)
		data->cam.pos_y += 10;
	if (keycode == KEY_I)
	{
		data->cam.isometric = 1;
		data->cam.plane = 0;
		data->cam.oblique = 0;
		data->cam.projection_angle = ANGLE2;
	}
	if (keycode == KEY_P)
	{
		data->cam.plane = 1;
		data->cam.isometric = 0;
		data->cam.oblique = 0;
	}
	if (keycode == KEY_O)
	{
		data->cam.plane = 0;
		data->cam.isometric = 0;
		data->cam.oblique = 1;
		data->cam.projection_angle = ANGLE1;
	}
	rotation(keycode, data);
	new_image(data);
	return (0);
}

int close_x(s_mlx *mlx)
{
	end(mlx);
	return (0);
}

int zoom(int button, int x, int y, fdf *data)
{
	if (button == M_SCR_U && data->cam.zoom)
		data->cam.zoom += 1;
	if (button == M_SCR_D && data->cam.zoom)
		data->cam.zoom -= 1;
	if (!data->cam.zoom)
		data->cam.zoom = 1;
	new_image(data);
	return (0);
}

void hooks_loop(fdf *data)
{
	mlx_key_hook(data->mlx.win, key_action, data);
	mlx_hook(data->mlx.win, 17, (1L << 17), close_x, &data->mlx);
	mlx_mouse_hook(data->mlx.win, zoom, data);
	mlx_loop(data->mlx.ptr);
}