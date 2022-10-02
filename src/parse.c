/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:00:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/02 17:21:35 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*getpath(char **envp);
static void	abspath(char **cmd, char **syspath);
static void	free_strarr(char **path);

void	eval(int argc, char **argv, char **envp, t_args *data)
{
	int		n;
	int		commands;
	char	***cmd;
	char	**syspath;

	syspath = ft_split(getpath(envp), ':');
	n = 0;
	commands = argc - 3;
	cmd = malloc(sizeof(cmd) * (commands + 1));
	while (n < commands)
	{
		cmd[n] = ft_split(argv[n + 2], ' ');
		abspath(cmd[n], syspath);
		n++;
	}
	free_strarr(syspath);
	cmd[n] = NULL;
	data->cmd = cmd;
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
}

void	cleanup(char ***cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free_strarr(cmd[i++]);
	free(cmd);
}

// Replace cmd with your full path if it exists, else leave as is.
static void	abspath(char **cmd, char **syspath)
{
	int		i;
	char	*bin;
	char	*fullpath;

	i = 0;
	bin = ft_strjoin("/", cmd[0]);
	while (syspath[i])
	{
		fullpath = ft_strjoin(syspath[i++], bin);
		if (access(fullpath, F_OK) == 0)
		{
			free(cmd[0]);
			free(bin);
			cmd[0] = fullpath;
			return ;
		}
		free(fullpath);
	}
	free(bin);
}

static void	free_strarr(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}

static char	*getpath(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (ft_strchr(*envp, '/'));
		envp++;
	}
	return (NULL);
}
