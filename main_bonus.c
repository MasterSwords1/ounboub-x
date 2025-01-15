/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:44:27 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/01 14:12:05 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	args_check(int ac)
{
	if (ac < 5)
	{
		write(2, "Invalid arguments number\n", 26);
		exit(EXIT_FAILURE);
	}
}

void	hd_args_check(int ac)
{
	if (ac < 6)
	{
		write(2, "Invalid arguments number\n", 26);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **envp)
{
	args_check(ac);
	if (hd_check(av[1]))
		heredoc_exec(av, ac, envp);
	else
		cmds_exec(av, ac, envp);
}
