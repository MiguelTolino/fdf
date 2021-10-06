/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:40:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/06 13:28:58 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

s_mlx create_window()
{
	s_mlx mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, SIZE_X, SIZE_Y, TITLE);
	mlx.img.ptr = mlx_new_image(mlx.ptr, SIZE_X, SIZE_Y);
	return(mlx);
}