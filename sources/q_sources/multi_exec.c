/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:12:03 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/07 16:12:06 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*void	childin_with_infile(t_struct **data, char **envp, int *pipefd)
{
	t_struct	*check;
	int			fdin;

	check = (*data)->next;
	fdin = open(check->content, O_RDONLY, 0644);
	if (fdin == -1)
	{
		pipe_use(pipefd, 2);
	}
	dup2(fdin, 0);
	close(fdin);
	pipe_use(pipefd, 1);
	exec_cmd(check->next->content, envp);
}

void	childout_with_outfile(t_struct **data, char **envp, int *pipefd)
{
	t_struct	*check;
	int			fdout;

	check = ft_structlast((*data));
	fdout = open(check->content, O_WRONLY, 0644);
	if (fdout == -1)
	{
		pipe_use(pipefd, 2);
	}
	dup2(fdout, 1);
	close(fdout);
	pipe_use(pipefd, 1);
	exec_cmd(check->next->content, envp);
}*/

void	child(char *content, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		ft_putstr_fd("pipe", 2);
	pid = fork();
	if (pid == 0)
	{
		pipe_use(pipefd, 1);
		exec_cmd(content, envp);
	}
	else
		pipe_use(pipefd, 0);
}

/*void	exec_multi_command(t_struct **data)
{
	int	i;

	i = 0;
	if(data->tkn == 2)
		i = 1;
	if(< infile cmd | cmd > outfile)

	if(cmd | cmd > outfile)
	return ;
}
*/