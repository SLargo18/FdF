/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:30:29 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/06 04:07:44 by slargo-b         ###   ########.fr       */
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

t_map	*parse(char *txt, int row, int col)
{
	char	*line;
	int		fd;
	t_map	*map;

	fd = open(txt, O_RDONLY);
	map = malloc(sizeof(t_map));
	if (fd < 0 || !map)
		return (free (map), NULL);
	map->row = count_lines(fd);
	close(fd);

	fd = open(txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		return (free_map(map), NULL);
		close(fd);
	}
	row = count_row(line);
	free (line);
	close(fd);

	map = malloc(sizeof(t_map));
	if (!map)
		return (free (map), NULL);
	init_map(map, row, col);
	if (!map->grid)
		return (free_map(map), NULL);
	fill_points(txt, map);
	return (map);
}

