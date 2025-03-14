/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:56:33 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/07 23:56:33 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	fill_points(char *txt, t_map *map)
{
	int		fd;
	int		row;
	int		col;
	char	*line;
	char	**split;

	row = 0;
	col = 0;
	fd = open(txt, O_RDONLY);
	if (fd < 0)
		return ;
	while (row < map->row)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("row cuantas2 ?: %d\n", map->row);
		split = ft_split(line, ' ');
		printf("entra?: %p\n", (void *)split);
		free(line);
		col = 0;
		while (col < map->col && split[col])
		{
			printf("entra?: %d\n", map->row);
			map->grid[row][col].x = col;
			map->grid[row][col].y = row;
			map->grid[row][col].z = ft_atoi(split[col]);
			map->grid[row][col].color = 0xFFFFFF;
			col++;
		}
		free_split(split, col);
		row++;
	}
}
