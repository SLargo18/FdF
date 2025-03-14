/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:05:20 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/14 05:53:43 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "include/fdf.h"
#include <stdlib.h>

int	my_key_esc(int keycode, t_fdf *param)
{
	if (keycode == 65307)
	{
		exit (1);
		mlx_destroy_window(param, param->win);
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Mapita :3");
	mlx_key_hook(win, my_key_esc, mlx);
	mlx_loop(mlx);
	return (0);
}

#include "include/fdf.h"
#include <stdio.h>

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
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

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	map = parse(argv[1], 0, NULL);
	if (!map)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	free_map(map);
	return (0);
}
 */