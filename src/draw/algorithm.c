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

static int abs_value(int num)
{
    if (num < 0)
        return (-num);
    return (num);
} /*creo que puedo usar abs de math.h*/

static void set_params(t_point p1, t_point p2, int *params)
{
    params[0] = abs_value(p2.x - p1.x);
    params[1] = abs_value(p2.y - p2.x);
    if (p1.x < p2.x)
        params[2] = 1;
    else 
        params[2] = -1;
    if (p1.y < p2.y)
        params [3] = 1;
    else 
        params [3] = -1;
    params [4] = params[0] - params[1];
}

static int get_color(t_point p1, t_point p2, float ratio)
{
    int color;

    if (p1.color == p2.color)
        return (p1.color);
    if (ratio < 0)
        rario = 0;
    if (ratio > 1)
        ratio = 1;
    color = p1.color + ((p2.color - p1.color) * ratio);
    return (color);
}

static void cuerrent(t_point p1, t_pointp2)
{
    t_point now;
    
    set_params(p1, p2, params);
    now = p1;

}

void draw_line(t_fdf *fdf, t_point p1, t_point p2) 
{
    int params [5];
    int e2;
    t_point now;
    float   distance;
    float   step;

    set_params(p1, p2, params);
    now = p1;
    step = 0;
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1y,2));
    while (now.x != p2.x || now.y != p2.y)
    {
        if (current.x >= 0 && current.x < WW && current.y >= 0 && current.y < WH)
            put_pixel(fdf, current.x, current.y), get_color(p1, p2, step / distance));
        e2 = 2 * params[4];
        if (e2 > -params[1])
        {
            params[4] -= params[1];
            current.x += params[2];
        }
        if (e2 < params[0])
        {
        params[4] -= params[0];
        current.x += params[3];
        }
        step++;
    }
}