/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:09:46 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/12 17:40:20 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_and_open_infile(t_struct **data)
{
	t_struct	*check;
	int			fd;

	check = *data;
	while (check && check->tkn != 4)
	{
		if (check->tkn == 2)
		{
			check = check->next;
			fd = open(check->content, O_RDONLY);
			if (fd == -1)
			{
				perror("infile");
				exit(0);
			}
			dup2(fd, 0);
			close(fd);
			return (1);
		}
		check = check->next;
	}
	return (0);
}

int	check_and_open_outfile(t_struct **data)
{
	t_struct	*check;
	int			mode;
	int			fd;

	check = *data;
	fd = 0;
	while (check && check->tkn != 4)
	{
		if (check->tkn == 3 || check->tkn == 6)
		{
			if (check->tkn == 3)
				mode = 1;
			else
				mode = 2;
			check = check->next;
			fd = mode_open_outfile(check->content, mode);	
		}
		check = check->next;
	}
	return (fd);
}

int	check_and_start_heredoc(t_struct **data)
{
	t_struct	*check;

	check = *data;
	while (check && check->tkn != 4)
	{
		if (check->tkn == 5)
		{
			check = check->next;
			do_heredoc(check->content);
			return (1);
		}
		check = check->next;
	}
	return (0);
}

void	exec_simple_command(t_struct **data)
{
	t_struct	*check;
	pid_t		pid;

	check = *data;
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		check_and_open_infile(data);
		check_and_open_outfile(data);
		check_and_start_heredoc(data);
		while (check && check->tkn != 1)
			check = check->next;
		exec_cmd(check->content, check->envp);
	}
}
