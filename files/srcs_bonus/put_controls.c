/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:12:52 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 11:15:41 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	put_controls1(t_mlx mlx)
{
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 50, 0xffffff, "CONTROLS");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 55, 0x00ff00, "________");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 80, 0xffffff, "Zoom: Scroll");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 100, 0xffffff, "Move");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 105, 0x00ff00, "____");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 130, 0xffffff, "W -> Up");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 150, 0xffffff, "S -> Down");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 170, 0xffffff, "A -> Left");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 190, 0xffffff, "D -> Right");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 220, 0xffffff, "Projection");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 225, 0x00ff00, "__________");
}

void	put_controls2(t_mlx mlx)
{
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 250, 0xffffff, "ISO -> I");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 270, 0xffffff, "PLAN -> P");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 290, 0xffffff, "OBLIQUE -> O");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 320, 0xffffff, "Rotation: Arrows");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 325, 0x00ff00, "________________");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 350, 0xffffff, "Left -> X Axis");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 370, 0xffffff, "Right -> Y Axis");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 390, 0xffffff, "Up -> Z Axis");
	mlx_string_put(mlx.ptr, mlx.win, SIZE_CONTROL
		/ 4, 410, 0xffffff, "Down -> Reset");
}

void	put_controls(t_mlx mlx)
{
	put_controls1(mlx);
	put_controls2(mlx);
}
