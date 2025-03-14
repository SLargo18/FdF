/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:53:19 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/14 17:04:56 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../../minilibx-linux/mlx.h"
# include <stdio.h>

# define WW 1800
# define WH 1800


typedef struct point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct map
{
	int		col;
	int		row;
	t_point	**grid;
}	t_map;

typedef struct fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*img;
	float	scale;
	float	z_scale;
	int		shift_x;
	int		shift_y;
	float	angle;
}	t_fdf;

int		count_lines(int fd);
int		count_row(char *line);
void	free_split(char **result, size_t i);
void	draw_map(t_fdf *fdf);
void	put_pixel(t_fdf *fdf, int x, int y, int color);
void	draw_line(t_fdf *fdf, t_point p1, t_point p2);
char	*get_next_line(int fd);
char	*ft_laquequiera(char *save, char *buffer);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	init_map(t_map *map, int row, int col);
void	fill_points(char *txt, t_map *map);
void	free_map(t_map *map);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
t_map	*parse(char *file, int fd, char *line);
void	draw_map(t_fdf *fdf);
void	put_pixel(t_fdf *fdf, int x, int y, int color);
void	draw_line(t_fdf *fdf, t_point p1, t_point p2);
int		get_color(t_point p1, t_point p2, float ratio);
#endif
