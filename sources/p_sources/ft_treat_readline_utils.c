#include "../minishell.h"

int	ft_is_sep(char *spl)
{
	if (spl[0] == '|' || spl[0] == '>' || spl[0] == '<')
		return (1);
	else
		return (0);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		x;
	int		y;
	int		nbr;
	char	*str;

	x = 0;
	nbr = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(sizeof(char), (nbr + 2));
	while (s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = ' ';
	x++;
	y = 0;
	while (s2[y])
	{
		str[x] = s2[y];
		y++;
		x++;
	}
	str[x] = '\0';
	free(s1);
	return (str);
}

void	ft_recreate_split(char **spl, int cut)
{
	char	**dupli;
	int		x;
	int		y;

	x = 0;
	while (spl[x])
		x++;
	dupli = malloc(sizeof(char *) * (x + 1));
	x = 0;
	y = 0;
	while (spl[x])
	{
		if (x == cut)
		{
			x++;
			continue;
		}
		dupli[y] = ft_strdup(spl[x]);
		x++;
		y++;
	}
	dupli[y] = NULL;
	fake_free_split(spl);
	x = 0;
	while (dupli[x])
	{
		spl[x] = ft_strdup(dupli[x]);
		x++;
	}
	spl[x] = NULL;
	free_split(dupli);
}

char	**ft_dupenvp(char **envp)
{
	int		x;
	char	**env;

	x = 0;
	while (envp[x])
		x++;
	env = malloc(sizeof(char *) * (x + 1));
	x = 0;
	while (envp[x])
	{
		env[x] = ft_strdup(envp[x]);
		x++;
	}
	env[x] = NULL;
	return (env);
}

int	ft_checker_struct(t_struct **stru)
{
	t_struct *head;

	head = (*stru);
	while ((*stru))
	{
		if ((*stru)->tkn == 2 || (*stru)->tkn == 3 || (*stru)->tkn == 5 || (*stru)->tkn == 6)
		{
			if ((*stru)->prev && (*stru)->prev->tkn != 1 && (*stru)->prev->tkn != 7 && (*stru)->prev->tkn != 4)
			{
				if ((*stru)->tkn == 2)
					ft_putstr_fd("Minishell: syntax error near unexpected token `<'\n", 2);
				else if ((*stru)->tkn == 3)
					ft_putstr_fd("Minishell: syntax error near unexpected token `>'\n", 2);
				else if ((*stru)->tkn == 5)
					ft_putstr_fd("Minishell: syntax error near unexpected token `<<'\n", 2);
				else if ((*stru)->tkn == 6)
					ft_putstr_fd("Minishell: syntax error near unexpected token `>>'\n", 2);
				return (0);
			}
		}
		(*stru) = (*stru)->next;
	}
	(*stru) = head;
	return (1);
}

void	ft_file_struct(char **spl, char **envp)
{
	t_struct	**stru;
	int			x;

	stru = malloc(sizeof(t_struct *));
	if (stru == NULL)
		return ;
	x = 0;
	*stru = NULL;
	while (spl[x])
	{
		ft_structadd_back(stru, ft_structnew(spl[x], envp));
		x++;
	}
	ft_go_tokens(stru);
	if (ft_checker_struct(stru))
	{
		ft_printf_stack((*stru));
		treat_data(stru);
	}
	free_split(spl);
	ft_free_struct(stru);
}
