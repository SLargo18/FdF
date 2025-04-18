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

static void	set_point(t_map *map, int row, int col, char *value)
{
	int	z;

	z = ft_atoi(value);
	map->grid[row][col].x = col;
	map->grid[row][col].y = row;
	map->grid[row][col].z = z;
	map->grid[row][col].color = get_color_hex(value, z);
}

static void	process_line(char *line, t_map *map, int row)
{
	char	**split;
	int		col;

	split = ft_split(line, ' ');
	if (!split || !line)
		return ;
	col = 0;
	while (col < map->col && split[col])
	{
		set_point(map, row, col, split[col]);
		free(split[col]);
		col++;
	}
	while (split[col])
	{
		free(split[col]);
		col++;
	}
	free(split);
}

void	fill_points(char *txt, t_map *map)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	line = NULL;
	fd = open(txt, O_RDONLY);
	if (fd < 0)
		return ;
	while (row < map->row)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		process_line(line, map, row);
		free(line);
		row++;
	}
	close(fd);
}
