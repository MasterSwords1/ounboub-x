/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:58:47 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/15 17:37:37 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_io(char **av, int ac, int *infile, int *outfile)
{
	*infile = open(av[1], O_RDONLY);
	*outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (*infile < 0)
		return (perror("input file error"), 0);
	if (*outfile < 0)
		return (perror("output file error"), 0);
	return (1);
}

void	set_pipe(int *p)
{
	if (pipe(p) < 0)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
}

void	close_fds(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
	if (fd3 >= 0)
		close(fd3);
	if (fd4 >= 0)
		close(fd4);
}
