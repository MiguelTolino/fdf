/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:27:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/05 12:48:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lib/libft/libft.h"


#define EXT ".fdf"

typedef struct map
{
	int **map;
	int x;
	int y;
} map;


void check_errors(int argc, char **argv);