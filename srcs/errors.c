/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:28:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/05 13:02:56 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void map_exists(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
	{
		perror("No map was detected");
		exit(1);
	}
}

void check_extension(char **argv)
{
	char *extension;

	if (!(extension = ft_strchr(argv[1], '.')) || strcmp(extension, EXT))
	{
		perror("No map extension '.fdf' was detected");
		exit(1);
	}
}

void check_errors(int argc, char **argv)
{
	map_exists(argc, argv);
	check_extension(argv);
}