/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfree_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:59:06 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 12:43:09 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	dfree(char **array)
{
	int	i;

	if (!array)
		return (-1);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
