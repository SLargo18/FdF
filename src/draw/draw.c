/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:51:17 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/15 21:30:25 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	apply_shift(t_point *p, t_fdf *fdf)
{
	p->x += fdf->shift_x + WW / 2;
	p->y += fdf->shift_y + WH / 3;
}

static void	apply_isometric(t_point *p, t_fdf *fdf)
{
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = (x - y) * cos(fdf->angle);
	p->y = (x + y) * sin(fdf->angle) - p->z;

}

static void	apply_scale(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->scale;
	p->y *= fdf->scale;
	p->z += fdf->scale;
}

static t_point	project_point(t_point p, t_fdf *fdf)
{
	t_point	projected;

	projected = p;
	apply_scale(&projected, fdf);
	apply_isometric(&projected, fdf);
	apply_shift(&projected, fdf);
	return (projected);
}

static void	connect_point(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

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

void	display_instructions(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0xFFFFFF, "Flechas: Mover");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0xFFFFFF, "raton: Zoom");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, 0xFFFFFF, "Q/E: Rotar");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70, 0xFFFFFF, "Z/X: Ajustar altura");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFFF, "R: Reiniciar");
	mlx_string_put(fdf->mlx, fdf->win, 10, 110, 0xFFFFFF, "ESC: Salir");
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
	connect_point(fdf);
	display_instructions(fdf);
}
