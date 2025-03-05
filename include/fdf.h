/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:25:25 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/05 21:59:32 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct map
{
	int		col;
	int		row;
	t_point	**grid;
}	t_map;

#endif