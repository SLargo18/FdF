#ifndef FDF_H
#define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

typedef struct point {
    int x;
    int y;
    int z;
} t_point;

typedef struct map {
    int col;
    int line;
    puntos **grid;
} t_map;

typedef struct program {
    void *mlx;
    void *win;
    t_map *map;
    void *img;
    float scale;
    int shift_x;
    int shift_y;
    float angle;
} t_program;

#endif