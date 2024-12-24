/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masterswords </var/spool/mail/masters      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:28:29 by masterswo         #+#    #+#             */
/*   Updated: 2024/12/24 03:17:26 by masterswo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	word_c(const char *s)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ':' || s[i + 1] == 0)
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
	sub = malloc(len + 2);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i++] = '/';
	sub[i] = 0;
	return (sub);
}

void	free_paths(char **paths)
{
	size_t	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

static int	set_paths(const char *s, char **paths)
{
	size_t	pos;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] != ':')
			count++;
		if (s[i] != ':' && (s[i + 1] == ':' || s[i + 1] == '\0'))
		{
			paths[pos] = ft_substr(s, i - count + 1, count);
			if (!paths[pos++])
				return (free_paths(paths), 0);
			count = 0;
		}
		i++;
	}
	paths[i] = NULL;
	return (1);
}

char	**path_split(const char *s)
{
	char	**paths;

	if (!s)
		return (NULL);
	paths = malloc((word_c(s) + 1) * sizeof(char *));
	if (!paths)
		return (NULL);
	if (set_paths(s, paths) == 0)
		return (NULL);
	return (paths);
}
