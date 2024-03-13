/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:39:56 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/08 19:40:04 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	here_in(char *limiter, int *pipefd)
{
	char	*tmp;
	int		len;

	limiter = ft_strtrim(limiter, "\"");
	len = ft_strlen(limiter);
	pipe_use(pipefd, 1);
	while (1)
	{
		ft_putstr_fd(">", 0);
		tmp = get_next_line(0);
		if (tmp == NULL)
		{
			free_multi_str(limiter, tmp);
			exit(0);
		}
		if (!ft_strncmp(tmp, limiter, len) && ((int)ft_strlen(tmp) == len + 1))
		{
			free_multi_str(limiter, tmp);
			exit(0);
		}
		ft_putstr_fd(tmp, 1);
		free(tmp);
	}
}

void	do_heredoc(char *content)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
		here_in(content, pipefd);
	else
	{
		pipe_use(pipefd, 0);
		waitpid(-1, NULL, 0);
	}
}
