/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:42:29 by slargo-b          #+#    #+#             */
/*   Updated: 2025/04/18 15:55:14 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	get_rgb_values(t_point *point)
{
	point->r = (point->color >> 16) & 0xFF;
	point->g = (point->color >> 8) & 0xFF;
	point->b = point->color & 0xFF;
}

static int	check_color(t_point p1, t_point p2, float ratio)
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
	return (-1);
}

int	get_color(t_point p1, t_point p2, float ratio)
{
	int	r;
	int	g;
	int	b;

	if (check_color(p1, p2, ratio) != -1)
	{
		if (p1.color == 0)
			return (0x0000FF00);
		if (p2.color == 0)
			return (0x00FF0000);
		return (p1.color);
	}
	get_rgb_values(&p1);
	get_rgb_values(&p2);
	r = p1.r + (p2.r - p1.r) * ratio;
	g = p1.g + (p2.g - p1.g) * ratio;
	b = p1.b + (p2.b - p1.b) * ratio;
	return ((r << 16) | (g << 8) | b);
}
