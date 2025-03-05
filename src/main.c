#include "fdf.h"

int main ()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 800, "FDF");
    return 0;
}