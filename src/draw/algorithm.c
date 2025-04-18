/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/07 23:58:09 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/07 23:58:09 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	set_params(t_point p1, t_point p2, int *params)
{
	params[0] = abs(p2.x - p1.x);
	params[1] = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		params[2] = 1;
	else
		params[2] = -1;
	if (p1.y < p2.y)
		params[3] = 1;
	else
		params[3] = -1;
	params[4] = params[0] - params[1];
}

static void	update_position(t_point *current, int *params, int e2)
{
	if (e2 > -params[1])
	{
		params[4] -= params[1];
		current->x += params[2];
	}
	if (e2 < params[0])
	{
		params[4] += params[0];
		current->y += params[3];
	}
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int		params[5];
	int		e2;
	t_point	current;
	float	distance;
	float	step;

	set_params(p1, p2, params);
	current = p1;
	step = 0;
	distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	while (current.x != p2.x || current.y != p2.y)
	{
		if (current.x >= 0 && current.x < WW && current.y >= 0
			&& current.y < WH)
			mlx_pixel_put(fdf->mlx, fdf->win, current.x, current.y,
				get_color(p1, p2, step / distance));
		e2 = 2 * params[4];
		update_position(&current, params, e2);
		step++;
	}
}
