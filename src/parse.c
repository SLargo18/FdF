/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:30:29 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/05 22:00:47 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*my_parse(char *txt)
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
}

