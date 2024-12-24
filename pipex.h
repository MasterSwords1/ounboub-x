/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masterswords </var/spool/mail/masters      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:10:51 by masterswo         #+#    #+#             */
/*   Updated: 2024/12/24 02:29:48 by masterswo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
void	free_paths(char **paths);
char	**path_split(const char *s);
char	**get_path(char	**envp);

#endif
