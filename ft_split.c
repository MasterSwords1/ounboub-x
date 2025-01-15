/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:52:25 by ariyad            #+#    #+#             */
/*   Updated: 2024/12/31 16:52:26 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	word_c(const char *s, char sep)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == sep || s[i + 1] == 0)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	l;
	size_t	i;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
		return (NULL);
	if (len > l - start)
		len = l - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

void	free_table(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

static int	set_strs(const char *s, char **split, char sep)
{
	size_t	pos;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] != sep)
			count++;
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
		{
			split[pos] = ft_substr(s, i - count + 1, count);
			if (!split[pos++])
				return (free_table(split), 0);
			count = 0;
		}
		i++;
	}
	return (split[pos] = NULL, 1);
}

char	**ft_split(const char *s, char sep)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((word_c(s, sep) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (set_strs(s, split, sep) == 0)
		return (NULL);
	return (split);
}
