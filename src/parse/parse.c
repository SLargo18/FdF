/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:30:29 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/27 13:17:56 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	validate_line_columns(char *line, int expected_columns)
{
	int	columns;

	columns = count_row(line);
	if (columns != expected_columns)
	{
		printf("Error: son %d, y hay %d\n[%s]\n", expected_columns, columns, line);
		return (0);
	}
	return (1);
}

static int	validate_lines(int fd, t_map *map)
{
	char	*line;
	int line_num = 1;

	line = get_next_line(fd);
	if (!line)
		return (0);
	map->col = count_row(line);
	while (line)
	{
		if (!validate_line_columns(line, map->col))
		{
			printf("Error %d\n", line_num); 
			return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
		line_num++;
	}
	return (1);
}

static int	prepare_map(char *file, t_map **map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	*map = malloc(sizeof(t_map));
	if (!(*map))
		return (close(fd), 0);
	(*map)->row = count_lines(fd);
	close(fd);
	return (1);
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
	int		fd;

	if (!prepare_map(file, &map))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0 || !validate_lines(fd, map))
		return (close(fd), free_map(map), NULL);
	close(fd);
	init_map(map, map->row, map->col);
	if (!map->grid)
		return (free_map(map), NULL);
	fill_points(file, map);
	return (map);
}
