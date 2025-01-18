/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:04:32 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/18 11:59:05 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec(char *av, char **envp, int *pipe, int infile)
{
	char	*cmd;
	char	**args;
	char	**paths;
	int		out;

	if (fork() == 0)
	{
		out = pipe[1];
		if (dup2(infile, 0) < 0 || dup2(out, 1) < 0)
			exit(EXIT_FAILURE);
		close(pipe[0]);
		paths = get_paths(envp);
		args = ft_split(av, ' ');
		if (ft_strncmp(args[0], "./", 2) == 0 || *args[0] == '/'
			|| !access(args[0], X_OK))
			cmd = av;
		else
			cmd = get_cmd_path(paths, args[0]);
		return (execve(cmd, args, envp), free_table(paths), free_table(args),
			write(2, "Command invalid\n", 17), exit(0), 1);
	}
	return (0);
}
