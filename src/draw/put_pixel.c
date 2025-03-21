/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 05:15:15 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/21 22:11:42 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	if (x < 0 || y < 0 || x >= WW || y >= WH)
		return ;
	pixel = mlx_get_data_addr(fdf->img, &bits_per_pixel, &size_line, &endian);
	if (!pixel)
		return ;
	pixel += ((y / 2) * (size_line) + (x) * (bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

