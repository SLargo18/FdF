/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:11:49 by slargo-b          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/18 16:05:27 by slargo-b         ###   ########.fr       */
=======
/*   Updated: 2025/04/23 18:55:29 by slargo-b         ###   ########.fr       */
>>>>>>> db60a487ce37f0420727919ac385793c5c7227b6
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->scale = 1;
	fdf->shift_x = 30;
	fdf->shift_y = 30;
	fdf->z_scale = 1;
	fdf->angle = 0.8;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
<<<<<<< HEAD
		exit(0);
=======
		close_win(fdf);
>>>>>>> db60a487ce37f0420727919ac385793c5c7227b6
	else if (keycode == 65362)
		fdf->shift_y -= 10;
	else if (keycode == 65364)
		fdf->shift_y += 10;
	else if (keycode == 65361)
		fdf->shift_x -= 10;
	else if (keycode == 65363)
		fdf->shift_x += 10;
	else if (keycode == 113)
		fdf->angle += 0.1;
	else if (keycode == 101)
		fdf->angle -= 0.1;
	else if (keycode == 122)
		fdf->z_scale += 0.5;
	else if (keycode == 120)
		fdf->z_scale -= 0.5;
	else if (keycode == 114)
		init_fdf(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 4)
		fdf->scale += (fdf->scale * 0.2);
	if (button == 5)
		fdf->scale -= (fdf->scale * 0.2);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}
