/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:11:32 by qdeviann          #+#    #+#             */
/*   Updated: 2024/03/07 16:11:37 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signalhandler(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;

	(void)argc;
	(void)argv;
	signal(SIGINT, signalhandler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str = readline("MINISH -> ");
		if (!str)
		{
			ft_printf("exit\n");
			break ;
		}
		if (str[0] == '\0')
			continue ;
		add_history(str);
		str = ft_checker(str);
		if (str)
			ft_treat_read(str, envp);
		while (wait(NULL) > 0)
			;
		if (str)
			free(str);
		str = NULL;
	}
	return (1);
}
