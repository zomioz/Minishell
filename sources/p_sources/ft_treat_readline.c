#include "../minishell.h"

static void	ft_treat_cmd(char **spl, int x)
{
	int	y;

	y = 0;
	if (spl[x + 1] && ft_is_sep(spl[x + 1]) == 0)
	{
		y = x + 1;
		while (spl[y] && ft_is_sep(spl[y]) == 0)
		{
			spl[x] = ft_strcat(spl[x], spl[y]);
			ft_recreate_split(spl, y);
		}
	}
}

void	ft_treat_read(char *str, char **envp)
{
	char	**spl;
	int		x;

	x = 0;
	spl = ft_split_sep(str);
	if (!spl)
		return ;
	ft_check_quote(spl);
	while(spl[x])
	{
		if (ft_is_sep(spl[x]))
		{
			if (spl[x + 1] && (spl[x][0] == '>' || spl[x][0] == '<'))
				x++;
			x++;
		}
		else
		{
			ft_treat_cmd(spl, x);
			x++;
		}
	}
	ft_file_struct(spl, envp);
}