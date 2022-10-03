/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:52:02 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 03:04:20 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		pipex(t_args *data);
static void		cmd_in(int *fd, t_args *data);
static void		cmd_out(int *fd, t_args *data);

int	main(int argc, char **argv, char **envp)
{
	t_args	data;

	if (argc != 5)
	{
		ft_printf("Invalid arguments\n");
		return (EXIT_FAILURE);
	}
	eval(argc, argv, envp, &data);
	pipex(&data);
	return (EXIT_SUCCESS);
}

static void	pipex(t_args *data)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		err_exit("pipe");
	pid = pfork();
	if (pid == 0)
		cmd_in(fd, data);
	wait(NULL);
	cmd_out(fd, data);
}

static void	cmd_in(int *fd, t_args *data)
{
	int		file_in;
	char	*filename;

	filename = data->argv[1];
	file_in = open(filename, O_RDONLY);
	if (file_in == -1)
	{
		cleanup(data->cmd);
		err_exit(filename);
	}
	dup2(file_in, STDIN_FILENO);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[READ_END]);
	execp(data->cmd[0], data);
}

static void	cmd_out(int *fd, t_args *data)
{
	int		file_out;
	char	*filename;

	filename = data->argv[4];
	file_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
	{
		cleanup(data->cmd);
		err_exit(filename);
	}
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[WRITE_END]);
	execp(data->cmd[1], data);
}
