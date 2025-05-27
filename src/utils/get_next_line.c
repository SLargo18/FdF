/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:14:17 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/27 12:36:27 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*ft_laquequiera(char *save, char *buffer)
{
	char	*rest;

	rest = ft_strjoin(save, buffer);
	if (!rest)
		return (NULL);
	free (save);
	return (rest);
}

static char	*get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save [i] != '\n')
		i++;
	if (save [i] == '\n' )
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (free(save), NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n' && save[i])
		line[i++] = '\n';
	return (line);
}

static char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	int		read_a;

	read_a = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!save)
		save = ft_calloc(1, sizeof(char));
	if (!buffer || !save)
		return (free(buffer), free(save), NULL);
	while (read_a > 0)
	{
		read_a = read(fd, buffer, BUFFER_SIZE);
		if (read_a < 0)
			return (free(buffer), free(save), NULL);
		buffer[read_a] = '\0';
		save = ft_laquequiera(save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

static char	*update_save(char *save)
{
	char	*new_save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && (save[i] != '\n'))
		i++;
	if (!save[i])
		return (free(save), NULL);
	if (!save[i + 1])
		return (free(save), NULL);
	new_save = ft_calloc(((ft_strlen(save) - i) + 1), sizeof(char));
	if (!new_save)
		return (free(save), NULL);
	i++;
	while (save[i])
		new_save[j++] = save[i++];
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	if (ft_strlen(save) == 0)
		return (free(save), save = NULL, NULL);
	line = get_line(save);
	save = update_save(save);
	return (line);
}
