/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:38:01 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/06 15:18:43 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->grid)
	{
		while (i < map->row)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}
