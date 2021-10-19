/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:26:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 20:50:57 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	check_errors(argc, argv);
	data->map = parse_map(argv[1]);
	data->map.range = range(data);
	printf("R: %i", data->map.range);
	data->cam = init_cam();
	data->mlx = create_window();
	display_img(data);
	hooks_loop(data);
	return (0);
}
