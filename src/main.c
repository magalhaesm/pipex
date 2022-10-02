/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:52:02 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/02 17:09:12 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		pipex(t_args *data);
static void		cmd_in(char *file, int *fd, t_args *data);
static void		cmd_out(char *file, int *fd, t_args *data);

int	main(int argc, char **argv, char **envp)
{
	int		status;
	t_args	data;

	if (argc != 5)
	{
		ft_printf("Invalid arguments\n");
		return (EXIT_FAILURE);
	}
	eval(argc, argv, envp, &data);
	status = pipex(&data);
	cleanup(data.cmd);
	return (status);
}

static int	pipex(t_args *data)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	status;

	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	pid1 = pfork();
	if (pid1 == 0)
		cmd_in(data->argv[1], fd, data);
	pid2 = pfork();
	if (pid2 == 0)
		cmd_out(data->argv[4], fd, data);
	close(fd[WRITE_END]);
	close(fd[READ_END]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_SUCCESS);
}

static void	cmd_in(char *file, int *fd, t_args *data)
{
	fd[READ_END] = open(file, O_RDONLY);
	if (fd[READ_END] == -1)
	{
		cleanup(data->cmd);
		err_exit(file);
	}
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	execp(data->cmd[0], data);
}

static void	cmd_out(char *file, int *fd, t_args *data)
{
	int	file_out;

	file_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
	{
		cleanup(data->cmd);
		err_exit(file);
	}
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	close(file_out);
	execp(data->cmd[1], data);
}
