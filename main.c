/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:44:27 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/15 17:42:29 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	args_check(int ac)
{
	if (ac != 5)
	{
		write(2, "Nedd 4 arguments\n", 18);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **envp)
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
