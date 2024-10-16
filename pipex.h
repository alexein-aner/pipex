/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knieve-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:34:03 by knieve-l          #+#    #+#             */
/*   Updated: 2024/10/16 14:38:08 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int st, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *s, char c);
void			pip_exec(char *cmd, char **env);
char			**pip_get_path(char **env);
char			*pip_get_exec(char *cmd, char **paths);
void			setup_pipe(int fd_in, int fd_out);
void			pip_exec(char *bin, char **env);
void			close_fds(int fd1, int fd2, int fd3, int fd4);

#endif
