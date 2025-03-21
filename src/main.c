/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:38:01 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/21 22:39:31 by slargo-b         ###   ########.fr       */
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
/* static void	init_fdf(t_fdf *fdf)
{
	fdf->scale = 30;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->angle = 0.8;
	fdf->z_scale = 1;
} */

static int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65362)
		fdf->shift_y -= 10;
	else if (keycode == 65364)
		fdf->shift_y += 10;
	else if (keycode == 65361)
		fdf->shift_x -= 10;
	else if (keycode == 65363)
		fdf->shift_x += 10;
	else if (keycode == 113)
		fdf->angle += 0.1;
	else if (keycode == 101)
		fdf->angle -= 0.1;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 4)
		fdf->scale += (fdf->scale * 0.1);
	else if (button == 5)
		fdf->scale -= (fdf->scale * 0.1);
	if (fdf->scale < 1)
		fdf->scale = 1;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}

static int	close_win(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	free_map(fdf->map);
	free(fdf);
	exit(0);
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
	map = parse(argv[1], 0, NULL);
	if (!map)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (free_map(map), (1));
	fdf->map = map;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (free_map(map), free(fdf), (1));
	fdf->win = mlx_new_window(fdf->mlx, WW - 900, WH - 900, "Mapita :3");
	if (!fdf->win)
		return (free_map(map), free(fdf), (1));
	fdf->img = NULL;
	fdf->scale = 10;
	fdf->shift_x = 30;
	fdf->shift_y = 30;
	fdf->z_scale = 3;
	fdf->angle = 0.8;
	draw_map(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
