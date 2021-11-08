/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:40:36 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 14:31:32 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_action(int keycode, t_fdf *data)
{
	if (keycode == K_ESC)
		end(&data->mlx);
	return (0);
}

int	close_x(t_mlx *mlx)
{
	end(mlx);
	return (0);
}

void	hooks_loop(t_fdf *data)
{
	mlx_key_hook(data->mlx.win, key_action, data);
	mlx_hook(data->mlx.win, 17, (1L << 17), close_x, &data->mlx);
	mlx_loop(data->mlx.ptr);
}
