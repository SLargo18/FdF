/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:51:17 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/21 23:05:42 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	display_instructions(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0xFFFFFF, "Flechas: Mover");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0xFFFFFF, "raton: Zoom");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, 0xFFFFFF, "Q/E: Rotar");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70, 0xFFFFFF, "Z/X: Ajustar altura");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFFF, "R: Reiniciar");
	mlx_string_put(fdf->mlx, fdf->win, 10, 110, 0xFFFFFF, "ESC: Salir");
}

static void	connect_point(t_fdf *fdf, t_point p1, t_point p2)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->map->row)
	{
		j = 0;
		while (j < fdf->map->col)
		{
			if (j < fdf->map->col - 1)
			{
				p1 = project_point(fdf->map->grid[i][j], fdf);
				p2 = project_point(fdf->map->grid[i][j + 1], fdf);
				draw_line(fdf, p1, p2);
			}
			if (i < fdf->map->row - 1)
			{
				p1 = project_point(fdf->map->grid[i][j], fdf);
				p2 = project_point(fdf->map->grid[i + 1][j], fdf);
				draw_line(fdf, p1, p2);
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_fdf *fdf)
{
	if (fdf->img)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = NULL;
	}
	if (!fdf->scale)
		fdf->scale = 3;
	if (!fdf->angle)
		fdf->angle = 0.8;
	connect_point(fdf, fdf->map->grid[0][0], fdf->map->grid[0][0]);
	display_instructions(fdf);
}
