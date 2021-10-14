/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:26:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/14 13:43:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	s_map map;
	s_mlx mlx;

	check_errors(argc, argv);
	map = parse_map(argv[1]);
	mlx = create_window();
	display_img(&mlx, map);
	free_map(map);
	hooks_loop(mlx);
	return (0);
}
