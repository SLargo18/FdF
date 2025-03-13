/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:51:17 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/10 13:21:38 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static  void    connect_point(t_fdf *fdf)
{
    int i;
    int j;
    t_point p1;
    t_point p2;

    i = 0;
    j = 0;
    while (i < fdf->map->row)
    {
        while (j < fdf->map->col)
        {
            if (j < fdf->map->col - 1)
            {
                
            }
        }
    }
}
void draw_map(t_fdf *fdf)
{
    if (fdf->img)
    {
        mlx_destroy_image(fdf->mlx, fdf->img);
        fdf->img = NULL;
    }
    fdf-img = mlx_new_image(fdf->mlx, WW, WH);}
    if (!fdf->img)
        return ;
    if (!fdf->scale)
        fdf->scale = 30;
    if(!fdf->angle)
        fdf->angle = 0.8;
    connect_point(fdf);
}