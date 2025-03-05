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
}puntos;

typedef struct get_point {
    int col;
    int line;
    puntos **grid;
} map;

#endif