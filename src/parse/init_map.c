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
	map->row = row;
	map->col = col;
	map->grid = malloc(sizeof(t_point *) * row); // puntero a cada fila de cada columna
	if (!map->grid)
		return ;
	while (i < row)
	{
		map->grid[i] = malloc(sizeof(t_point) * col); // cada x,y,z es un t_point
		if (!map->grid[i])
		{
			while (--i >= 0)
				free(map->grid[i]);
			free(map->grid); 
			map->grid = NULL; // return ; ?
		}
		i++;
	}
}
