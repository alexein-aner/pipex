/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knieve-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:39:34 by knieve-l          #+#    #+#             */
/*   Updated: 2024/10/16 14:46:46 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	pipe_fd[2];
	int	fin_fd;
	int	fout_fd;
	int	id;

	if (ac != 5)
		return (1);
	pipe(pipe_fd);
	fin_fd = open(av[1], O_RDONLY);
	fout_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	id = fork();
	if (id == 0)
	{
		setup_pipe(fin_fd, pipe_fd[1]);
		close_fds(fin_fd, pipe_fd[0], pipe_fd[1], 0);
		pip_exec(av[2], env);
		exit(0);
	}
	id = fork();
	if (id == 0)
	{
		setup_pipe(pipe_fd[0], fout_fd);
		close_fds(fout_fd, pipe_fd[0], pipe_fd[1], 0);
		pip_exec(av[3], env);
		exit(0);
	}
	close_fds(fin_fd, fout_fd, pipe_fd[0], pipe_fd[1]);
	return (wait(0), wait(0), 0);
}
