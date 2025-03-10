/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 05:15:15 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/08 05:40:01 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	t_img	*img;
	char	*dst;

	if (x < 0 || x >= 500 || y < 0 || y >= 500)
		return ;
	img = fdf->img;
	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
} // todo esto debe estar malo. 
