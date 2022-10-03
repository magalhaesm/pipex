/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:54:34 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 13:51:14 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pfork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		err_exit("fork");
	return (pid);
}

void	err_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	execp(char *argv, char **envp)
{
	char	**cmd;
	char	*fullpath;

	cmd = ft_split(argv, ' ');
	fullpath = abspath(cmd[0], envp);
	if (fullpath)
		execve(fullpath, cmd, envp);
	else
		execve(argv, cmd, envp);
	free_strarr(cmd);
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(argv, STDERR_FILENO);
	ft_putendl_fd(": command not found...", STDERR_FILENO);
	exit(127);
}
