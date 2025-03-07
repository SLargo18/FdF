/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:51:17 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/05 21:51:18 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void draw_map(t_fdf *fdf)
{
    int x;
    int y;
    
    y = 0;
    x = 0;
    while (x < fdf->map->row)
    {
        while (x < fdf->map->col)
        {
            if (x < fdf->map>col -1)
            draw_line(fdf, fdf->map->grid[y][x])
        }
    }
}