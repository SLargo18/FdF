#include "fdf.h"

int count_lines(int fd)
{
    int i;
    char *line;

    i = 0;
    while ((line = get_next_line(fd)))
    {
        i++;
        free(line);
    }
    return (i);
}