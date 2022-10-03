/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:50:58 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 13:37:15 by mdias-ma         ###   ########.fr       */
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

void	execp(char *argv, char **envp);
char	*abspath(char *argv, char **environ);
void	free_strarr(char **arr);
int		pfork(void);
void	err_exit(const char *msg);

#endif
