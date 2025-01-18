/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:44:27 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/18 12:20:55 by ariyad           ###   ########.fr       */
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
