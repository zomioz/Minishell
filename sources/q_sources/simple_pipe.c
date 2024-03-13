/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:10:49 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/07 16:10:52 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pipe_use(int *pipefd, int mode)
{
	if (mode == 2)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	if (mode == 1)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
	}
	if (mode == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
	}
}

void	childin(char *content, char **envp, int *pipefd)
{
	pipe_use(pipefd, 1);
	exec_cmd(content, envp);
}

void	childout(char *content, char **envp, int *pipefd)
{
	pipe_use(pipefd, 0);
	exec_cmd(content, envp);
}

void	do_simple_pipe(t_struct **data)
{
	pid_t		pid1;
	int			pipefd[2];
	t_struct	*check;

	check = ft_structlast((*data));
	pipe(pipefd);
	pid1 = fork();
	if (pid1 == 0)
		childin((*data)->content, (*data)->envp, pipefd);
	if (pid1 != 0)
	{
		pid1 = fork();
		if (pid1 == 0)
			childout(check->content, check->envp, pipefd);
		if (pid1 != 0)
			pipe_use(pipefd, 2);
	}
	waitpid(-1, NULL, 0);
}
