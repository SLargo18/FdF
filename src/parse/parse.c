/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:30:29 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/21 22:41:13 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*parse(char *file, int fd, char *line)
{
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return ((close (fd), NULL));
	map->row = count_lines(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free_map(map), NULL);
	line = get_next_line(fd);
	if (!line)
		return (free_map(map), NULL);
	map->col = count_row(line);
	free(line);
	close(fd);
	init_map(map, map->row, map->col);
	if (!map->grid)
		return (free_map(map), NULL);
	fill_points(file, map);
	return (map);
}
