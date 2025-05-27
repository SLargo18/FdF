/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:29:39 by slargo-b          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/18 12:37:42 by slargo-b         ###   ########.fr       */
=======
/*   Updated: 2025/04/19 22:19:03 by slargo-b         ###   ########.fr       */
>>>>>>> db60a487ce37f0420727919ac385793c5c7227b6
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
<<<<<<< HEAD
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = (x - y) * cos(fdf->angle);
	p->y = (x + y) * sin(fdf->angle) - p->z * fdf->z_scale;
=======
	int		x;
	int		y;
	int		center_x;
	int		center_y;

	center_x = fdf->map->col / 2;
	center_y = fdf->map->row / 2;
	x = p->x - center_x;
	y = p->y - center_y;
	p->x = x * cos(fdf->angle) - y * sin(fdf->angle);
	p->y = x * sin(fdf->angle) + y * cos(fdf->angle);
	p->y -= p->z * fdf->z_scale;
>>>>>>> db60a487ce37f0420727919ac385793c5c7227b6
}

static void	apply_scale(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->scale;
	p->y *= fdf->scale;
	p->z += fdf->scale;
}

t_point	project_point(t_point p, t_fdf *fdf)
{
	t_point	projected;

	projected = p;
	apply_scale(&projected, fdf);
	apply_isometric(&projected, fdf);
	apply_shift(&projected, fdf);
	return (projected);
}
