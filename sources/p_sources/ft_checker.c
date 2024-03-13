#include "../minishell.h"

int	ft_count_quote(char *str, char c)
{
	int	x;
	int	quote;

	quote = 0;
	x = 0;
	while (str[x])
	{
		if (str[x] == c)
			quote++;
		x++;
	}
	if (quote % 2)
		return (1);
	return (0);
}

char	*ft_re_readline(char *str, char c)
{
	char	*tempo;

	tempo = NULL;
	while (ft_count_quote(str, c))
	{
		tempo = readline(">");
		str = ft_strjoin_free(str, tempo);
		free(tempo);
		tempo = NULL;
	}
	add_history(str);
	return (str);
}

int	ft_checker_quote_before(char *str, int x, char c)
{
	int	quote;

	quote = 0;
	while (x >= 0)
	{
		if (str[x] == c)
			quote++;
		x--;
	}
	if (quote % 2)
		return (0);
	return (1);
}

char	*ft_checker_quote(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (ft_checker_quote_before(str, x, 39) && str[x] == 34)
		{
			if (ft_count_quote(str, 34))
				str = ft_re_readline(str, 34);
		}
		if (ft_checker_quote_before(str, x, 34) && str[x] == 39)
		{
			if (ft_count_quote(str, 39))
				str = ft_re_readline(str, 39);
		}
		x++;
	}
	return (str);
}

int	ft_checker_before(char *str, int x)
{
	if (x == 0)
		return (0);
	x--;
	while (x >= 0 && str[x] != 124)
	{
		if (str[x] != 32 && str[x] != 124 && str[x] != 60 && str[x] != 62)
			return (1);
		x--;
	}
	return (0);
}

char *ft_checker(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (NULL);
	while (str[x])
	{
		if (str[x] == 124)
		{
			if (ft_checker_before(str, x) == 0)
			{
				free(str);
				ft_putstr_fd("Minishell: syntax error near unexpected token |\n", 2);
				return (NULL);
			}
		}
		x++;
	}
	str = ft_checker_quote(str);
	return (str);
}