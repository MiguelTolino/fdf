/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:40:36 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 21:23:29 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_action(int keycode, fdf *data)
{
	if (keycode == KEY_W)
		data->cam.pos_y -= 5;
	if (keycode == KEY_A)
		data->cam.pos_x -= 5;
	if (keycode == KEY_D)
		data->cam.pos_x += 5;
	if (keycode == KEY_S)
		data->cam.pos_y += 5;
	if (keycode == KEY_I)
	{
		data->cam.isometric = 1;
		data->cam.plane = 0;
	}
	if (keycode == KEY_P)
	{
		data->cam.plane = 1;
		data->cam.isometric = 0;
	}
	mlx_clear_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_image(data->mlx.ptr, data->mlx.img.ptr);
	data->mlx.img = create_img(data->mlx);
	display_img(data);
	return (0);
}

int close_win(int keycode, s_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(EXIT_SUCCESS);
	}

	return (0);
}

int close_x(s_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int zoom(int button, int x, int y, fdf *data)
{
	if (button == M_SCR_U && data->cam.zoom)
	{
		data->cam.zoom += 1;
		mlx_clear_window(data->mlx.ptr, data->mlx.win);
		data->mlx.img = create_img(data->mlx);
		display_img(data);
		printf("M:%i \n", data->cam.zoom);
	}
	if (button == M_SCR_D && data->cam.zoom)
	{
		data->cam.zoom -= 1;
		mlx_clear_window(data->mlx.ptr, data->mlx.win);
		data->mlx.img = create_img(data->mlx);
		display_img(data);
	}
	if (!data->cam.zoom)
		data->cam.zoom = 1;
}

void hooks_loop(fdf *data)
{
	mlx_hook(data->mlx.win, 2, (1L << 0), close_win, &data->mlx);
	mlx_key_hook(data->mlx.win, key_action, data);
	mlx_hook(data->mlx.win, 17, (1L << 17), close_x, &data->mlx);
	mlx_mouse_hook(data->mlx.win, zoom, data);
	mlx_loop(data->mlx.ptr);
}