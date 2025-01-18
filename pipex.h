/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:35:33 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/18 17:13:08 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin_plus(char *s1, char *s2);
char	*ft_strjoin(const char *s1, const char *s2);
int		set_io(char **av, int ac, int *infile, int *outfile);
void	set_pipe(int *p);
void	close_fds(int fd1, int fd2, int fd3, int fd4);
void	free_table(char **split);
char	**ft_split(const char *s, char sep);
char	**get_paths(char	**envp);
char	*get_cmd_path(char **paths, char *cmd);
int		exec(char *av, char **envp, int *pipe, int infile);

#endif
