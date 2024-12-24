/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masterswords </var/spool/mail/masters      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:13:03 by masterswo         #+#    #+#             */
/*   Updated: 2024/12/24 03:23:35 by masterswo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	char	**paths;
	int		p[2];

	if (ac != 5)
		return (write(2, "Need 4 arguments to work", 24), 1);
	paths = get_path(envp);
	if (pipe(p) < 0)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
}