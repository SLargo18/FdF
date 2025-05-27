/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 04:53:19 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/27 14:32:13 by slargo-b         ###   ########.fr       */
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
	int	r;
	int	g;
	int	b;
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
void	draw_line(t_fdf *fdf, t_point p1, t_point p2);
char	*get_next_line(int fd);
char	*ft_laquequiera(char *save, char *buffer);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
void	init_map(t_map *map, int row, int col);
void	process_line(char *line, t_map *map, int row);
void	free_map(t_map *map);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
t_map	*parse(char *file);
void	draw_map(t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_point p1, t_point p2);
int		get_color_hex(char *str, int z);
int		get_color(t_point p1, t_point p2, float ratio);
t_point	project_point(t_point p, t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);
int		mouse_hook(int button, int x, int y, t_fdf *fdf);
void	init_fdf(t_fdf *fdf);
int		close_win(t_fdf *fdf);
int 	count_words(const char *s, char c);
t_map	*prepare_map(char *file);

#endif
