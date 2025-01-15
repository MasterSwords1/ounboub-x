/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:35:33 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/15 15:51:03 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
void	ft_putstr_fd(const char *str, int fd);
void	args_check(int ac);
void	hd_args_check(int ac);
int		hd_check(char *str);
int		hd_set_io(char **av, int ac, int *outfile);
void	heredoc_exec(char **av, int ac, char **envp);
void	cmds_exec(char **av, int ac, char **envp);
char	*get_next_line(int fd);
int		create_hd_tmp(void);

#endif