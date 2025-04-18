/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:10:30 by slargo-b          #+#    #+#             */
/*   Updated: 2025/04/18 16:12:38 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

static int	hex_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

static int	parse_hex_color(char *ptr_hex)
{
	int	color;

	color = 0;
	if (*ptr_hex == '0' && (*(ptr_hex + 1) == 'x' || *(ptr_hex + 1) == 'X'))
		ptr_hex += 2;
	while (*ptr_hex && *ptr_hex != '\n')
	{
		color = color * 16 + hex_char_to_int(*ptr_hex);
		ptr_hex++;
	}
	return (color);
}

int	get_color_hex(char *str, int z)
{
	int		color;
	char	*ptr_hex;

	ptr_hex = ft_strchr(str, ',');
	if (ptr_hex)
	{
		ptr_hex++;
		color = parse_hex_color(ptr_hex);
	}
	else
	{
		if (z < 0)
			color = 0x0000FFFF;
		else if (z == 0)
			color = 0x00FFFFFF;
		else if (z < 10)
			color = 0x0000FF00;
		else if (z < 30)
			color = 0x00FFFF00;
		else if (z < 70)
			color = 0x00FFA500;
		else
			color = 0x00FF0000;
	}
	return (color);
}
