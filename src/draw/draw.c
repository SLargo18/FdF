/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:51:17 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/08 05:39:48 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void draw_map(t_fdf *fdf)
{
	int x, y;
	y = 0;
	while (y < fdf->map->row)
	{
		x = 0;
		while (x < fdf->map->col)
		{
			if (x < fdf->map->col - 1)
				draw_line(fdf, fdf->map->grid[y][x], fdf->map->grid[y][x + 1]);
			if (y < fdf->map->row - 1)
				draw_line(fdf, fdf->map->grid[y][x], fdf->map->grid[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
