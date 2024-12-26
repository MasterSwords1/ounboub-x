/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masterswords </var/spool/mail/masters      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:10:51 by masterswo         #+#    #+#             */
/*   Updated: 2024/12/26 22:55:22 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define COMMAND_NOT_FOUND "Command not found"
# define X_PERMISSION_DENIED "Permision denied to run command"
# define CMD_NOT_FETCHED "Could not fetch command"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
void	free_table(char **paths);
char	**ft_split(const char *s, char sep);
char	**get_path(char	**envp);
char	*get_cmd_path(const char *cmd, char **paths);
char	*ft_strdup(const char *s);
char	*ft_strjoin_plus(char *s1, char *s2);
char	*ft_strjoin(const char *s1, const char *s2);
void	putstr_fd(const char *s, int fd);
char	*fetch_str(int fd);
void	cmd1_exec(const char **args, char **paths, char **envp, int *p);

#endif
