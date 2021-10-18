/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:26:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/18 11:40:03 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	check_errors(argc, argv);
	data->map = parse_map(argv[1]);
	data->mlx = create_window();
	display_img(data);
	//free_map(map);
	hooks_loop(data->mlx);
	free(data);
	return (0);
}
