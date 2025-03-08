/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:58:09 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/07 23:58:09 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	abs_value(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int	dx = abs_value(p2.x - p1.x);
	int	dy = abs_value(p2.y - p1.y);
	int	sx = 1;
	int	sy = 1;
	int	err = dx - dy;
	int e2;

	if (p1.x > p2.x)
		sx = -1;
	if (p1.y > p2.y)
		sy = -1;

	while (p1.x != p2.x || p1.y != p2.y)
	{
		put_pixel(fdf->img, p1.x, p1.y, p1.color);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			p1.y += sy;
		}
	}
}
