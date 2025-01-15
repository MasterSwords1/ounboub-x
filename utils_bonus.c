/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:36:49 by ariyad            #+#    #+#             */
/*   Updated: 2024/12/31 16:51:37 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(const char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin_plus(char *s1, char *s2)
{
	char	*new;
	ssize_t	i;
	ssize_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (new = ft_strdup(s1), free(s1), new);
	if (!s1)
		return (new = ft_strdup(s2), free(s2), new);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (free(s1), free(s2), NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = 0;
	return (free(s1), free(s2), new);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	ssize_t	i;
	ssize_t	j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = 0;
	return (new);
}
