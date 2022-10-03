/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:52:02 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 13:41:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	pipex(int argc, char **argv, char **envp);
static void	redirect(char *argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
	{
		pipex(argc, argv, envp);
		return (EXIT_SUCCESS);
	}
	ft_printf("Invalid arguments\n");
	return (EXIT_FAILURE);
}

static void	pipex(int argc, char **argv, char **envp)
{
	int	n;
	int	file_in;
	int	file_out;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		n = 3;
		file_out = openfd(argv[argc - 1], AP);
		here_doc(argv[2]);
	}
	else
	{
		n = 2;
		file_in = openfd(argv[1], RD);
		file_out = openfd(argv[argc - 1], WR);
		dup2(file_in, STDIN_FILENO);
	}
	while (n < argc - 2)
		redirect(argv[n++], envp);
	dup2(file_out, STDOUT_FILENO);
	execp(argv[argc - 2], envp);
}

static void	redirect(char *argv, char **envp)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		err_exit("redirect");
	pid = pfork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		execp(argv, envp);
	}
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
	wait(NULL);
}
