#include "../minishell.h"

int	ft_is_quote(char *str, char c)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == c)
			return (1);
		x++;
	}
	return (0);
}

int	ft_get_first_quote(char **spl)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (!spl)
		return (0);
	while (spl[x])
	{
		while (spl[x][y])
		{
			if (spl[x][y] == 34)
				return (34);
			if (spl[x][y] == 39)
				return (39);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

static void	ft_treat_quote(char **spl, int x, char c)
{
	int	y;

	y = x + 1;
	while (spl[y] && ft_is_quote(spl[y], c) == 0)
	{
		spl[x] = ft_strcat(spl[x], spl[y]);
		ft_recreate_split(spl, y);
	}
	if (spl[y] && ft_is_quote(spl[y], c) == 1)
	{
		spl[x] = ft_strcat(spl[x], spl[y]);
		ft_recreate_split(spl, y);
	}
}

void	ft_check_quote(char **spl)
{
	int	quote;
	int	x;

	x = 0;
	quote = ft_get_first_quote(spl);
	while (quote && spl[x])
	{
		if (quote && ft_count_quote(spl[x], quote))
		{
			ft_treat_quote(spl, x, quote);
		}
		x++;
	}
}