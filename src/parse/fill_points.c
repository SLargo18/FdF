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

static int	get_color_hex(char *str)
{
	int		color;
	char	*ptr_hex;

	color = 0x00FFFFFF;
	ptr_hex = ft_strchr(str, ',');
	if (ptr_hex)
	{
		ptr_hex++;
		if (*ptr_hex == '0' && (*(ptr_hex + 1) == 'x' || *(ptr_hex + 1) == 'X'))
			ptr_hex += 2;
		color = 0;
		while (*ptr_hex && *ptr_hex != '\n')
		{
			color = color * 16;
			if (*ptr_hex >= '0' && *ptr_hex <= '9')
				color += *ptr_hex - '0';
			else if (*ptr_hex >= 'a' && *ptr_hex <= 'f')
				color += *ptr_hex - 'a' + 10;
			else if (*ptr_hex >= 'A' && *ptr_hex <= 'F')
				color += *ptr_hex - 'A' + 10;
			ptr_hex++;
		}
	}
	return (color);
}

static void	set_point(t_map *map, int row, int col, char *value)
{
	map->grid[row][col].x = col;
	map->grid[row][col].y = row;
	map->grid[row][col].z = ft_atoi(value);
	map->grid[row][col].color = get_color_hex(value);
}

void	fill_points(char *txt, t_map *map)
{
	int		fd;
	int		row;
	int		col;
	char	*line;
	char	**split;

	row = 0;
	fd = open(txt, O_RDONLY);
	if (fd < 0)
		return ;
	while (row < map->row)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		free(line);
		col = 0;
		while (col < map->col && split[col])
		{
			set_point(map, row, col, split[col]);
			col++;
		}
		free_split(split, col);
		row++;
	}
	close(fd);
}
