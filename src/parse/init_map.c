void	init_map(t_map *map, int row, int col)
{
    int i;
    
    i = o;
    map->row = row;
    map->col = col;
    map->grid = malloc(sizeof(t_point *) * row);
    if (!map->grid)
        return (free(*map));
    while (i < row)
    {
        map->grid[i] = malloc(sizeof(t_point) * col);
        if (!map->grid[i])
        {
            while (--i >= 0)
                free(map->grid[i]);
            return (free(map->grid), map->grid = NULL));
        }
        i++;
    }
}