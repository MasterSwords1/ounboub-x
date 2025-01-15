/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:04:32 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/15 18:51:15 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec(char *av, char **envp, int out, int infile)
{
	char	*cmd;
	char	**args;
	char	**paths;

	if (fork() != 0)
		return (1);
	if (dup2(infile, 0) < 0 || dup2(out, 1) < 0)
		exit(EXIT_FAILURE);
	paths = get_paths(envp);
	args = ft_split(av, ' ');
	if (access(args[0], X_OK))
	{
		cmd = get_cmd_path(paths, args[0]);
		return (execve(cmd, args, envp), free_table(args), free_table(paths),
			free(cmd), close_fds(out, -1, -1, -1), 1);
	}
	cmd = av;
	return (execve(av, args, envp), free_table(paths), free_table(args),
		close_fds(out, -1, -1, -1), 1);
}
