/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:28:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 12:43:09 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	throw_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
	return (0);
}

void	map_exists(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
		throw_error("No map has been detected | Exit");
}

void	check_extension(char **argv)
{
	char	*extension;

	extension = ft_strchr(argv[1], '.');
	if (!(extension) || strcmp(extension, EXT))
		throw_error("No map extension '.fdf' was detected | Exit");
}

void	check_errors(int argc, char **argv)
{
	map_exists(argc, argv);
	check_extension(argv);
}
