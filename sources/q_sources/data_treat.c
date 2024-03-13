/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_treat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:08:36 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/12 17:41:09 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	trim_tab(char **cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while(cmd[i])
	{
		tmp = ft_strtrim(cmd[i], " ");
		free(cmd[i]);
		cmd[i] = ft_substr(tmp, 0, ft_strlen(tmp));
		free(tmp);
		i++;
	}
}

int	ft_quote(char *content)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\"')
			count++;
		i++;
	}
	return(count);
}

void	exec_cmd(char *content, char **envp)
{
	char	**cmd;
	char	*path;

	if (ft_strchr(content, '/'))
	{
		cmd = find_cmd_with_path(content);
		if (cmd)
			path = content;
		else
			path = NULL;
	}
	else
	{
		if (!ft_quote(content))
			cmd = ft_split(content, ' ');
		else 
		{
			cmd = ft_split(content, '\"');
			trim_tab(cmd);
		}
		path = find_path(cmd, envp);
	}
	check_cmd(path, cmd, content);
	execve(path, cmd, envp);
	free_all(path, cmd);
}

int	check_pipe(t_struct **data)
{
	t_struct	*check;
	int			npipe;

	check = *data;
	npipe = 0;
	while (check->next != NULL)
	{
		if (check->tkn == 4)
			npipe++;
		check = check->next;
	}
	return (npipe);
}

void	treat_data(t_struct **data)
{
	int		npipe;
	int		savefd[2];
	int		pipefd[2];

	savefd[0] = dup(0);
	savefd[1] = dup(1);
	npipe = check_pipe(data);
	if (!npipe)
		exec_simple_command(data);
	else
	{
		while (npipe >= 0)
		{
			exec_pipe(data, npipe, pipefd);
			find_next_block(data);
			npipe--;
		}
	}
	restore_stdfd(savefd);
}
