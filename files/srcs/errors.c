/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:28:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/06 18:49:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		throw_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
	return (0);
}

void map_exists(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
		throw_error("No map has been detected");
}

void check_extension(char **argv)
{
	char *extension;

	if (!(extension = ft_strchr(argv[1], '.')) || strcmp(extension, EXT))
		throw_error("No map extension '.fdf' was detected");
}

void check_errors(int argc, char **argv)
{
	map_exists(argc, argv);
	check_extension(argv);
}