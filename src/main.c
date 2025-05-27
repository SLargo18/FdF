/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:38:01 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/27 13:16:32 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	close_win(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = NULL;
	}
	mlx_destroy_display(fdf->mlx);
	free_map(fdf->map);
	free (fdf->mlx);
	free (fdf);
	exit(0);
}

static int	checker_map(char *argv[])
{
	char	*fdf;
	char	*valid;
	int		i;
	int		name_len;

	fdf = argv[1];
	valid = ft_strrchr(fdf, '.');
	if (!valid)
		return (write(1, "Error\n", 6), (0));
	if (ft_strcmp(valid, ".fdf") != 0)
		return (write(1, "Error\n", 6), (0));
	if (valid == fdf)
		return (write(1, "Error\n", 6), (0));
	name_len = valid - fdf;
	i = 0;
	while (i < name_len)
	{
		if (fdf[i] == '.')
			return (write(1, "Error\n", 6), (0));
		i++;
	}
	return (1);
}

static t_fdf	*start(t_map *map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (free_map(map), free(fdf), NULL);
	fdf->map = map;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (free_map(map), free(fdf), NULL);
	fdf->win = mlx_new_window(fdf->mlx, WW, WH, "Mapita :3");
	if (!fdf->win)
		return (free_map(map), free(fdf), NULL);
	fdf->img = NULL;
	return (fdf);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_fdf	*fdf;

	if (argc != 2 || !checker_map(argv))
		return (write(1, "Error\n", 6), (1));
	map = parse(argv[1]);
	if (!map)
		return (write(1, "Error\n", 6), (1));
	fdf = start(map);
	init_fdf(fdf);
	draw_map(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
