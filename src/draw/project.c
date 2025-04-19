/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:29:39 by slargo-b          #+#    #+#             */
/*   Updated: 2025/04/19 22:19:03 by slargo-b         ###   ########.fr       */
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
	p->y = (x + y) * sin(fdf->angle) - p->z * fdf->z_scale;
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
