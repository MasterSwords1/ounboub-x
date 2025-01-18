/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:04:32 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/18 12:21:25 by ariyad           ###   ########.fr       */
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

static int	exec(char *av, char **envp, int *pipe, int infile)
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
		exec(av[i], envp, p, infile);
		close_fds(infile, p[1], -1, -1);
		infile = p[0];
		i++;
	}
	p[1] = outfile;
	exec(av[i], envp, p, infile);
	close_fds(outfile, infile, -1, -1);
	while (wait(NULL) >= 0)
		;
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
		exec(av[i], envp, p, infile);
		close_fds(infile, p[1], -1, -1);
		infile = p[0];
		i++;
	}
	p[1] = outfile;
	exec(av[i], envp, p, infile);
	close_fds(outfile, infile, -1, -1);
	while (wait(NULL) >= 0)
		;
	unlink("/tmp/hd_tmp");
}
