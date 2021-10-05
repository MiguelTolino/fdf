/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:26:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/05 11:40:07 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		perror("No map was detected");
		exit(1);
	}
	argv = NULL;

	void *mlx_ptr = mlx_init();
	void *mlx_win = mlx_new_window(mlx_ptr, 200, 200, "Fdf");
	mlx_loop(mlx_ptr);
	return (0);
}
