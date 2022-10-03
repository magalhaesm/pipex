/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:24:08 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 13:50:05 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_limiter(char *line, char *limiter);

void	here_doc(char *limiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		err_exit("here_doc");
	line = "";
	while (TRUE)
	{
		ft_printf("> ");
		line = get_next_line(STDIN_FILENO);
		if (is_limiter(line, limiter))
		{
			free(line);
			close(STDIN_FILENO);
			get_next_line(STDIN_FILENO);
			break ;
		}
		ft_putstr_fd(line, fd[WRITE_END]);
		free(line);
	}
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
}

static int	is_limiter(char *line, char *limiter)
{
	int	content;
	int	length;

	content = ft_strncmp(line, limiter, ft_strlen(limiter)) == 0;
	length = (ft_strlen(line) - 1) == ft_strlen(limiter);
	return (content && length);
}
