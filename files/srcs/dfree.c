/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:59:06 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/18 10:54:37 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int dfree(char **array)
{
	int i;

	if (!array)
		return(-1);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

int dfree_int(int **array)
{
	int i;

	if (!array)
		return(-1);
	i = 0;
	while (i < 11)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

int free_map(s_map map)
{
	return (0);
}