/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:46:01 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/08 19:47:17 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	size_struct(t_struct **stru)
{
	t_struct	*check;
	int			i;

	check = *stru;
	i = 0;
	while (check)
	{
		check = check->next;
		i++;
	}
	return (i);
}

int	mode_open_outfile(char *file, int mode)
{
		int fd;

		if (mode == 1)
			fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("outfile");
			exit(0);
		}
		dup2(fd, 1);
		close(fd);
		return (1);
}

void	free_multi_str(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

void	free_all(char *str, char **tab)
{
	free(str);
	free_split(tab);
}
