/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:04:32 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/15 17:43:15 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	hd_check(char *str)
{
	if (ft_strncmp("here_doc", str, 9) == 0)
		return (1);
	return (0);
}

static int	heredoc(char *limiter)
{
	char	*input;
	int		hd_tmp;

	hd_tmp = create_hd_tmp();
	write(1, "heredoc> ", 10);
	input = get_next_line(0);
	if (!input)
		return (hd_tmp);
	while (ft_strncmp(limiter, input, ft_strlen(input) - 1) != 0
		|| *input == '\n')
	{
		ft_putstr_fd(input, hd_tmp);
		free(input);
		write(1, "heredoc> ", 10);
		input = get_next_line(0);
		if (!input)
			break ;
	}
	close(hd_tmp);
	hd_tmp = create_hd_tmp();
	return (free(input), hd_tmp);
}

static int	exec(char *av, char **envp, int out, int infile)
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
	if (!args)
		return (write(2, "Paths error\n", 13), exit(EXIT_FAILURE), 0);
	if (access(args[0], X_OK))
	{
		cmd = get_cmd_path(paths, args[0]);
		if (!cmd)
			return (free_table(args), free_table(paths),
				write(2, "Invalid command\n", 17), exit(0), 0);
		return (execve(cmd, args, envp), free_table(args), free_table(paths),
			free(cmd), close_fds(out, -1, -1, -1), 1);
	}
	cmd = av;
	return (execve(av, args, envp), free_table(paths), free_table(args),
		close_fds(out, -1, -1, -1), 1);
}

void	cmds_exec(char **av, int ac, char **envp)
{
	int		p[2];
	int		infile;
	int		outfile;
	int		i;

	args_check(ac);
	set_io(av, ac, &infile, &outfile);
	i = 2;
	while (i < ac - 2)
	{
		set_pipe(p);
		exec(av[i], envp, p[1], infile);
		close_fds(infile, p[1], -1, -1);
		infile = p[0];
		i++;
	}
	set_pipe(p);
	dup2(outfile, 1);
	exec(av[i], envp, outfile, infile);
	while (wait(NULL) >= 0)
		;
	close_fds(p[0], p[1], infile, outfile);
}

void	heredoc_exec(char **av, int ac, char **envp)
{
	int		p[2];
	int		infile;
	int		outfile;
	int		i;

	hd_args_check(ac);
	infile = heredoc(av[2]);
	hd_set_io(av, ac, &outfile);
	i = 3;
	while (i < ac - 2)
	{
		set_pipe(p);
		exec(av[i], envp, p[1], infile);
		close_fds(infile, p[1], -1, -1);
		infile = p[0];
		i++;
	}
	set_pipe(p);
	dup2(outfile, 1);
	exec(av[i], envp, outfile, infile);
	while (wait(NULL) >= 0)
		;
	close_fds(p[0], p[1], infile, outfile);
	unlink("/tmp/hd_tmp");
}
