/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:38:01 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/08 06:10:34 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->grid)
	{
		while (i < map->row)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}

int	main(int argc, char *argv[])
{
	t_map	*map; 
	t_fdf	*fdf;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	map = (parse(argv[1], 0, NULL));
	if (!map)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
	{
		free_map(map);
		return (1);
	}
	fdf->map = map;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 500, 500, "Mapita :3");
	draw_map(fdf);
	free_map(map);
	mlx_loop(fdf);
	return (0);
}
