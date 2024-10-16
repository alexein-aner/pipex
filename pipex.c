/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knieve-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:39:34 by knieve-l          #+#    #+#             */
/*   Updated: 2024/10/16 13:29:25 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pip_exec(char *cmd, char **env);
static char	**pip_get_path(char **env);
static char	*pip_get_exec(char *cmd, char **paths);

void setup_fds(int fd_in, int fd_out, int fd1, int fd2, int fd3)
{
    dup2(fd_in, STDIN_FILENO);
    dup2(fd_out, STDOUT_FILENO);

    close(fd1);
    close(fd2);
    close(fd3);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	int		file1_fd;
	int		file2_fd;
	int		id;
	char		*file2;
	char		*cmd1;
	char		*cmd2;

	av[1] = av[1];
	file2 = av[4];
	cmd1 = av[2];
	cmd2 = av[3];
	if (ac != 5)
		return (1);
	pipe(pipe_fd);
	file1_fd = open(av[1], O_RDONLY);
	file2_fd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	id = fork();
	if (id == 0)
	{
		setup_fds(file1_fd, pipe_fd[1], file1_fd, pipe_fd[0], pipe_fd[1]);
		pip_exec(cmd1, env);
		exit(0);
	}
	id = fork();
	if (id == 0)
	{
		setup_fds(pipe_fd[0], file2_fd, file2_fd, pipe_fd[0], pipe_fd[1]);
		pip_exec(cmd2, env);
		exit(0);
	}
	close(file1_fd);
	close(file2_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}

static void	pip_exec(char *bin, char **env)
{
	char	**args;
	char	**paths;

	paths = pip_get_path(env);
	args = ft_split(bin, ' ');
	args[0] = pip_get_exec(args[0], paths);
	execve(args[0], args, env);
}

static char	**pip_get_path(char **env)
{
	char	**paths;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			break ;
		env++;
	}
	paths = ft_split(*env + 5, ':');
	return (paths);
}

static char	*pip_get_exec(char *cmd, char **paths)
{
	char	*path;

	if ((ft_strncmp(cmd, "./", 2) == 0) && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		paths++;
	}
	return (NULL);
}
