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

int	get_color(t_point p1, t_point p2, float ratio)
{
	if (p1.color == 0)
		return (0x0000FF00);
	if (p2.color == 0)
		return (0x00FF0000);
	if (p1.color == p2.color)
		return (p1.color);

	if (ratio < 0)
		ratio = 0;
	if (ratio > 1)
		ratio = 1;
	int r1 = (p1.color >> 16) & 0xFF;
	int g1 = (p1.color >> 8) & 0xFF;
	int b1 = p1.color & 0xFF;

	int r2 = (p2.color >> 16) & 0xFF;
	int g2 = (p2.color >> 8) & 0xFF;
	int b2 = p2.color & 0xFF;

	int r = r1 + (r2 - r1) * ratio;
	int g = g1 + (g2 - g1) * ratio;
	int b = b1 + (b2 - b1) * ratio;

	return ((r << 16) | (g << 8) | b);
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
	int     params[5];
	int     e2;
	t_point current;
	float   distance;
	float   step;

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
