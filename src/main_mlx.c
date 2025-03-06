/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:05:20 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/06 15:17:14 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int	my_key_esc(int keycode, void *param, void *mlx)
{
	if (keycode == 65307)
	{
		exit (1);
		mlx_destroy_window(mlx, param);
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Mapita :3");
	mlx_key_hook(win, my_key_esc, mlx);
	mlx_loop(mlx);
	return 0;
}
