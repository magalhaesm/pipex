/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:00:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 13:50:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*getpath(char **envp);

char	*abspath(char *argv, char **environ)
{
	int		n;
	char	*bin;
	char	*fullpath;
	char	**syspath;

	n = 0;
	syspath = ft_split(getpath(environ), ':');
	bin = ft_strjoin("/", argv);
	while (syspath[n])
	{
		fullpath = ft_strjoin(syspath[n++], bin);
		if (access(fullpath, F_OK) == 0)
		{
			free(bin);
			return (fullpath);
		}
		free(fullpath);
	}
	free_strarr(syspath);
	free(bin);
	return (NULL);
}

void	free_strarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
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
