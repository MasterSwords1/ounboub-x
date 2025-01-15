/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:01:56 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/15 18:55:37 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	*get_cmd_path(char **paths, char *cmd)
{
	char	*valid_cmd;
	char	*tmp;
	ssize_t	i;

	i = -1;
	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (NULL);
	while (paths[++i])
	{
		valid_cmd = ft_strjoin(paths[i], tmp);
		if (!valid_cmd)
			return (free(tmp), NULL);
		if (access(valid_cmd, X_OK) == 0)
			break ;
		free(valid_cmd);
		valid_cmd = NULL;
	}
	free(tmp);
	return (valid_cmd);
}
