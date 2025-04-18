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

static int	hex_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

static int	parse_hex_color(char *ptr_hex)
{
	int	color;

	color = 0;
	if (*ptr_hex == '0' && (*(ptr_hex + 1) == 'x' || *(ptr_hex + 1) == 'X'))
		ptr_hex += 2;
	while (*ptr_hex && *ptr_hex != '\n')
	{
		color = color * 16 + hex_char_to_int(*ptr_hex);
		ptr_hex++;
	}
	return (color);
}

int	get_color_hex(char *str, int z)
{
	int		color;
	char	*ptr_hex;

	ptr_hex = ft_strchr(str, ',');
	if (ptr_hex)
	{
		ptr_hex++;
		color = parse_hex_color(ptr_hex);
	}
	else
	{
		if (z < 0)
			color = 0x0000FFFF;
		else if (z == 0)
			color = 0x00FFFFFF;
		else if (z < 10)
			color = 0x0000FF00;
		else if (z < 30)
			color = 0x00FFFF00;
		else if (z < 70)
			color = 0x00FFA500;
		else
			color = 0x00FF0000;
	}
	return (color);
}

static void	set_point(t_map *map, int row, int col, char *value)
{
	int	z;

	z = ft_atoi(value);
	map->grid[row][col].x = col;
	map->grid[row][col].y = row;
	map->grid[row][col].z = z;
	map->grid[row][col].color = get_color_hex(value, z);
}

void	process_line(char *line, t_map *map, int row)
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
