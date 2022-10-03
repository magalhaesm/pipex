/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:50:58 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/10/03 13:41:20 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define READ_END 0
# define WRITE_END 1

# define RD 0
# define WR 1
# define AP 2

# include "libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

int		openfd(char *filename, int flag);
void	here_doc(char *limiter);
void	execp(char *argv, char **envp);
char	*abspath(char *argv, char **environ);
void	free_strarr(char **arr);
int		pfork(void);
void	err_exit(const char *msg);

#endif
