/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:58:47 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/15 17:44:25 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	set_io(char **av, int ac, int *infile, int *outfile)
{
	*infile = open(av[1], O_RDONLY);
	*outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND);
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

int	hd_set_io(char **av, int ac, int *outfile)
{
	*outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	if (*outfile < 0)
		return (perror("output file error"), 0);
	return (1);
}

int	create_hd_tmp(void)
{
	int	hd_tmp;

	hd_tmp = open("/tmp/hd_tmp", O_CREAT | O_APPEND | O_RDWR, 0777);
	if (hd_tmp < 0)
		return (perror("tmp file error"), exit(0), -1);
	return (hd_tmp);
}
