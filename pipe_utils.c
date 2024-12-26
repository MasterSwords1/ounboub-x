/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masterswords </var/spool/mail/masters      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:57:03 by masterswo         #+#    #+#             */
/*   Updated: 2024/12/24 12:06:32 by masterswo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	putstr_fd(const char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

char	*fetch_str(int fd)
{
	char	*str;
	char	*tmp;
	ssize_t	buff;

	str = NULL;
	buff = 1;
	while (buff != 0)
	{
		tmp = str;
		str = malloc(10);
		if (!str)
			return (free(tmp), putstr_fd("fetching infile failed", 2), NULL);
		buff = read(fd, str, 10);
		if (buff == -1)
			return (free(str), free(tmp), NULL);
		str[buff] = 0;
		str = ft_strjoin_plus(tmp, str);
		if (!str)
			return (putstr_fd("fetching infile failed", 2), NULL);
		if (buff < 10)
			buff = 0;
	}
	return (str);
}

char	*get_cmd_path(const char *cmd, char **paths)
{
	size_t	i;
	char	*valid_cmd;
	int		file_ok;
	int		file_exec;

	i = 0;
	file_ok = -1;
	file_exec = -1;
	while (paths[i])
	{
		valid_cmd = ft_strjoin(paths[i], cmd);
		if (!valid_cmd)
		{
			putstr_fd(CMD_NOT_FETCHED, 2);
			exit(EXIT_FAILURE);
		}
		file_ok = access(valid_cmd, F_OK);
		file_exec = access(valid_cmd, X_OK);
		if (file_ok == 0 && file_exec == 0)
			break ;
	}
	if (file_ok == -1)
		return (putstr_fd(COMMAND_NOT_FOUND, 2), exit(EXIT_FAILURE), NULL);
	if (file_ok == 0 && file_exec == -1)
		return (putstr_fd(X_PERMISSION_DENIED, 2), exit(EXIT_FAILURE), NULL);
	return (valid_cmd);
}
