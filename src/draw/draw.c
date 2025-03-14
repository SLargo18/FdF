/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:51:17 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/14 06:19:49 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void apply_shift(t_point *p, t_fdf *fdf)
{
	p->x += fdf->shift_x + WW / 2;
	p->y += fdf->shift_y + WH / 3;
}

static void	apply_isometric (t_point *p, t_fdf *fdf)
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
	p->z *= fdf->scale / 2;
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
	int	i;
	int	j;
	t_point	p1;
	t_point	p2;

	i = 0;
	j = 0;
	while (i < fdf->map->row)
	{
		while (j < fdf->map->col)
		{
			if (j < fdf->map->col - 1)
			{
				p1 = project_point(fdf->map->grid[i][j], fdf);
				p2 = project_point(fdf->map->grid[i][j + 1], fdf);
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
	fdf->img = mlx_new_image(fdf->mlx, WW, WH);
	if (!fdf->img)
		return ;
	if (!fdf->scale)
		fdf->scale = 30;
	if (!fdf->angle)
		fdf->angle = 0.8;
	connect_point(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}