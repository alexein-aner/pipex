/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knieve-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:34:03 by knieve-l          #+#    #+#             */
/*   Updated: 2024/10/15 16:29:48 by knieve-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>  // For fork, execvp, pipe, dup2, close
# include <sys/types.h>  // For pid_t
# include <sys/wait.h>   // For wait
# include <fcntl.h>  // For open, O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC
# include <stdlib.h>  // For malloc, free, exit
# include <stdio.h>   // For perror

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
int					ft_strlen(char *str);
int					ft_strncmp( char *s1,  char *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup( char *s1);
char				*ft_substr(char  *s, unsigned int st, size_t len);
char				*ft_strjoin(char  *s1, char  *s2);
char				**ft_split(char  *s, char c);

#endif
