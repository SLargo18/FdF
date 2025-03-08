/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:42:01 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/08 05:47:10 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_row(char *line)
{
	int	count;
	int	i;
	int	wrd;

	count = 0;
	i = 0;
	wrd = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !wrd)
		{
			wrd = 1;
			count++;
		}
		else if (line[i] == ' ')
			wrd = 0;
		i++;
	}
	return (count);
}

int	count_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		i++;
		free(line);
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}
