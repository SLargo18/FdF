/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/08 00:00:43 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/08 00:00:43 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_map(t_map *map, int row, int col)
{
	int	i;

	i = 0;
	map->grid = malloc(sizeof(t_point *) * row);
	if (!map->grid)
	{
		map->grid = NULL;
		return ;
	}
	while (i < row)
	{
		map->grid[i] = malloc(sizeof(t_point) * col);
		if (!map->grid[i])
		{
			while (--i >= 0)
				free(map->grid[i]);
			free(map->grid);
			return ;
		}
		i++;
	}
}

void	free_map(t_map *map)
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
	map->col = 0;
	map->row = 0;
	free(map);
}
