/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_procs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masterswords </var/spool/mail/masters      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:25:35 by masterswo         #+#    #+#             */
/*   Updated: 2024/12/26 22:54:26 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1_exec(const char **av, char **paths, char **envp, int *p)
{
	char	*cmd_path;
	char	*content;
	char	**args;
	int		in_fd;

	in_fd = open(av[1], O_RDONLY);
	if (in_fd < 0)
	{
		perror("Open error");
		exit(EXIT_FAILURE);
	}
	dup2(in_fd, 0);
	dup2(p[1], 1);
	(cmd_path) && (args = ft_split(av[2], ' '), cmd_path = get_cmd_path(args[0], paths));
	if (fork() == 0)
	{
		if (execve(cmd_path, args + 1, envp) == -1)
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
