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
	while (row < map->row) // line = gnl(fd) &&
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		free(line);
		while (col < map->col && split[col])
		{
			map->grid[row][col].x = col;
			map->grid[row][col].y = row;
			map->grid[row][col].z = ft_atoi(split[col]);
			map->grid[row][col].color = 0xFFFFFF;

				printf("punto x": %d\n", row, col, map->grid[row][col].x);
				printf("punto y": %d\n", row, col, map->grid[row][col].y);
				printf("punto z": %d\n", row, col, map->grid[row][col].z);
			col++;
		}
		free_split(split, col);
		row++;
	}
	close(fd);
}
