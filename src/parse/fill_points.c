void    fill_points(char *txt, t_map *map)
{
    int     fd;
    int     row;
    int		col;
    char    *line;
    char    **split;

    row = 0;
    col = 0;
    fd = open(txt, O_RDONLY);
    if (fd < 0)
        return ; //es void :v
    while (row < map->row)
    {
        line = get_next_line(fd)
        if (!line)
            break;
        split = ft_split(line, ' ');
        free(line);
        while (col < map->col && split[col])
        {
            map->grid[row][col].x = col
            map->grid[row][col].y = row
            map->grid[row][col].z = ft_atoi(split[col]);
            col++;
        }
        free_split(split);
        row++;
    }
    close(fd)
}