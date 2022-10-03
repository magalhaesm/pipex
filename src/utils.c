/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:54:34 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 02:35:04 by mdias-ma         ###   ########.fr       */
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

void	err_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	execp(char **cmd, t_args *data)
{
	execve(cmd[0], cmd, data->envp);
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putendl_fd(": command not found...", STDERR_FILENO);
	cleanup(data->cmd);
	exit(127);
}
