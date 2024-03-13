/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:41:20 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/08 19:41:24 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_cmd(char *path, char **cmd, char *content)
{
	if (path == NULL)
	{
		if (ft_strchr(content, '/'))
			ft_putendl_fd("no such file or directory", 2);
		if (!ft_strchr(content, '/'))
			ft_putendl_fd("command not found", 2);
		free_all(path, cmd);
		exit(2);
	}
}

char	**find_cmd_with_path(char *content)
{
	char	*tmp;
	char	**result;
	int		check;

	check = access(content, F_OK | X_OK);
	if (check == 0)
	{
		tmp = ft_strrchr(content, '/');
		if (!ft_quote(tmp))
			result = ft_split(tmp, ' ');
		else
		{ 
			result = ft_split(tmp, '\"');
			trim_tab(result);
		}
		return (result);
	}
	return (NULL);
}

char	**find_envpath(char **envp)
{
	int		i;
	char	*tmp;
	char	**result;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			tmp = ft_strtrim(envp[i], "PATH=");
			result = ft_split(tmp, ':');
			free(tmp);
			return (result);
		}
		i++;
	}
	return (NULL);
}

int	ft_access(char *path, char *cmds)
{
	int		check;
	char	*cmd;

	cmd = ft_strjoin(path, cmds);
	check = access(cmd, F_OK | X_OK);
	free(cmd);
	if (check == 0)
		return (1);
	else
		return (0);
}

char	*find_path(char **cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	**paths;
	char	*result;

	i = 0;
	paths = find_envpath(envp);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (ft_access(tmp, cmd[0]))
		{
			result = ft_strjoin(tmp, cmd[0]);
			free_all(tmp, paths);
			return (result);
		}
		free(tmp);
		i++;
	}
	free_split(paths);
	return (0);
}
