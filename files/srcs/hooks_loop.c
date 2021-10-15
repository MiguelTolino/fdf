/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:40:36 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/15 10:23:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void hooks_loop(s_mlx mlx)
{
	mlx_hook(mlx.win, 2, (1L<<0), close_win, &mlx);
	mlx_hook(mlx.win, 17, (1L<<17), close_x, &mlx);
	mlx_loop(mlx.ptr);
}