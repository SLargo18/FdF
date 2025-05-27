/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slargo-b <slargo-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:15:56 by slargo-b          #+#    #+#             */
/*   Updated: 2025/05/27 14:09:28 by slargo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	a;
	unsigned int	i;

	a = 0;
	i = 0;
	while (src[a] != '\0')
	{
		a++;
	}
	if (size > 0)
	{
		while (i < (size - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (a);
}

int	count_words(const char *s, char c)
{
	size_t	count;
	int		inside_word;
	int     i;

	count = 0;
	i = 0;
	inside_word = 0;
	while (s[i])
	{
		if (s[i] != c && !inside_word && s[i + 1])
		{
			inside_word = 1;
			count++;
		}
		else if (s[i] == c)
			inside_word = 0;
		i++;
	}
	return (count);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	char		*word;
	size_t		len;

	while (**s == c)
		(*s)++;
	start = *s;
	len = 0;
	while (**s && **s != c)
	{
		len++;
		(*s)++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

void	free_split(char **result, size_t i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	if (word_count == 0)
		return (ft_calloc(1, sizeof(char *)));
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(&s, c);
		if (!result[i])
			return ((free_split(result, i), (NULL)));
		i++;
	}
	result[i] = NULL;
	return (result);
}
