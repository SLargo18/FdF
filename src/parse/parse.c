/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:30:29 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/27 16:45:31 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	validate_line_columns(char *line, int expected_columns)
{
	int	columns;

	columns = count_words(line, ' ');
	if (columns != expected_columns)
		return (0);
	return (1);
}

static int	validate_lines(int fd, t_map *map, char *file)
{
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	map->col = count_words(line, ' ');
	while (line)
	{
		if (!validate_line_columns(line, map->col))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map->col);
}

t_map	*prepare_map(char *file)
{
	int		fd;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	map->row = count_lines(fd);
	close(fd);
	map->col = validate_lines(fd, map, file);
	if (!map->col)
		return (free_map(map), NULL);
	return (map);
}

static void	fill_points(char *txt, t_map *map)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	line = NULL;
	fd = open(txt, O_RDONLY);
	if (fd < 0)
		return ;
	while (row <= map->row)
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

t_map	*parse(char *file)
{
	t_map	*map;

	map = prepare_map(file);
	if (!map)
		return (NULL);
	init_map(map, map->row, map->col);
	if (!map->grid)
		return (free_map(map), NULL);
	fill_points(file, map);
	return (map);
}
