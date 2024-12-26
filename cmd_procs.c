/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_procs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masterswords </var/spool/mail/masters      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:25:35 by masterswo         #+#    #+#             */
/*   Updated: 2024/12/24 12:41:22 by masterswo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1_exec(const char **args, char **paths, int *p)
{
	char	*cmd_path;
	char	*content;
	int		in_fd;

	in_fd = open(args[1], O_RDONLY);
	if (in_fd < 0)
	{
		perror("Open error");
		exit(EXIT_FAILURE);
	}
	dup2(in_fd, 0);
	dup2(p[1], 1);
	cmd_path = get_cmd_path(cmd, paths);
	if (fork() == 0)
	{
		if (execve() == -1)
		{
			free(cmd_path);
			strerror(errno);
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
	else
		wait(NULL);
}
