/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:30:29 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/06 04:43:30 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int count_col(char *line)
{
	int i;
	int col;
	int len;

	i = 0;
	col = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !len)
		{
			len = 1;
			col++;
		}
		else if (line[i] == ' ')
			len = 0;
		i++;
	}
	return (col);
}

t_map	*parse(char *file)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (free (map), NULL);
	map->row = count_lines(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	line = get_next_line(fd);
	map->col = count_row(line);
	free(line);
	close(fd);
	init_map(map, map->row, map->col);
	if (!map->grid)
		return (free_map(map), NULL);
	fill_points(file, map);
	return (map);
}


