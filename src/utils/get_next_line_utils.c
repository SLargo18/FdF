/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:01:10 by slargo-b          #+#    #+#             */
/*   Updated: 2025/03/15 20:39:40 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	totalsz;
	void	*pr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	totalsz = nmemb * size;
	pr = malloc(totalsz);
	if (pr == NULL)
		return (NULL);
	ft_bzero(pr, totalsz);
	return (pr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	size_t	i;
	size_t	j;
	char	*strresult;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	i = 0;
	j = 0;
	strresult = ft_calloc((ls1 + ls2) + 1, sizeof(char));
	if (!strresult)
		return (NULL);
	while (s1[i] != '\0')
	{
		strresult[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		strresult[i++] = s2[j++];
	return (strresult);
}
