/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:40:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 14:29:37 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	end(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(EXIT_SUCCESS);
}

void	new_image(t_fdf *data)
{
	mlx_destroy_image(data->mlx.ptr, data->mlx.img.ptr);
	data->mlx.img = create_img(data->mlx);
	display_img(data);
}

t_img	create_img(t_mlx mlx)
{
	t_img	img;

	img.ptr = mlx_new_image(mlx.ptr, SIZE_X, SIZE_Y);
	img.data = mlx_get_data_addr(img.ptr, &img.bbp,
			&img.size_line, &img.endian);
	if (!(img.ptr) || !(img.data))
		throw_error("Minilibx Error");
	return (img);
}

t_mlx	create_window(void)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, SIZE_X, SIZE_Y, TITLE);
	if (!(mlx.ptr) || !(mlx.win))
		throw_error("Minilibx Error");
	mlx.img = create_img(mlx);
	return (mlx);
}
