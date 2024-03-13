/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:10:49 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/12 17:39:37 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	restore_stdfd(int *savefd)
{
	dup2(savefd[0], 0);
	close(savefd[0]);
	dup2(savefd[1], 1);
	close(savefd[1]);
}

void	find_next_block(t_struct **data)
{
	while ((*data) && (*data)->tkn != 4)
		(*data) = (*data)->next;
	if ((*data) && (*data)->tkn == 4)
		(*data) = (*data)->next;
}

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

void	exec_pipe(t_struct **data, int npipe, int *pipefd)
{
	t_struct	*check;
	pid_t		pid;
	int			check_out;

	check = *data;
	if (pipe(pipefd) == -1)
		strerror(errno);
	pid = fork();
	if (pid == -1)
		strerror(errno);
	if (pid == 0)
	{
		check_and_start_heredoc(data);
		check_and_open_infile(data);
		check_out = check_and_open_outfile(data);
		if (!check_out && npipe != 0)
			pipe_use(pipefd, 1);
		while (check && check->tkn != 1)
			check = check->next;
		exec_cmd(check->content, check->envp);
	}
	else
		pipe_use(pipefd, 0);
}
