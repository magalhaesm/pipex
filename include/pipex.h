/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:50:58 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 02:35:26 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_END 0
# define WRITE_END 1

# include "libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**envp;
	char	***cmd;
}	t_args;

int		pfork(void);
void	eval(int argc, char **argv, char **envp, t_args *data);
void	execp(char **cmd, t_args *data);
void	cleanup(char ***cmd);
void	err_exit(char *msg);

#endif
