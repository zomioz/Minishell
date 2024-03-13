#include "../minishell.h"

int	ft_find_first_quote(char *str, int x)
{
	int	y;

	y = 0;
	while (y < x)
	{
		if (str[y] == 34)
		{
			y++;
			while (str[y] != 34 && y < x)
				y++;
			if (y == x)
				return (34);
		}
		else if (str[y] == 39)
		{
			y++;
			while (str[y] != 39 && y < x)
				y++;
			if (y == x)
				return (39);
		}
		y++;

	}
	return (0);
}

int	ft_is_between_quote(char *str, int x)
{
	int	quote;
	int	count;

	count = 0;
	quote = ft_find_first_quote(str, x);
	while (quote && x >= 0)
	{
		if (str[x] == quote)
			count++;
		x--;
	}
	if (count % 2)
		return (1);
	else
		return (0);
}

int ft_count(char *str)
{
	int	x;
	int	nbr;

	nbr = 0;
	x = 0;
	while (str[x])
	{
		if (str[x] == 32 && str[x + 1] && str[x + 1] != 32 && ft_is_between_quote(str, x) == 0)
			nbr++;
		x++;
	}
	return (nbr);
}

static int	ft_sublen(char *str, int start)
{
	int	x;

	x = 0;
	while (str[start])
	{
		if (str[start] == 32 && ft_is_between_quote(str, start) == 0)
			break;
		start++;
		x++;
	}
	return (x);
}

static int	ft_substart(char *str, int check)
{
	static int	start;

	if (!start || check == -1)
		start = 0;
	if (check == 0 || check == -1)
		return (0);
	while(str[start])
	{
		if (str[start] == 32 && ft_is_between_quote(str, start) == 0)
		{
			while (str[start] == 32 && str[start + 1] && str[start + 1] == 32)
				start++;
			break; 
		}
		while (str[start] && ft_is_between_quote(str, start) == 1)
			start++;
		start++;
	}
	start++;
	return (start);
}

char **ft_split_sep(char *str)
{
	int	nbr;
	char	**dest;
	int		x;
	int		start;

	x = 0;
	nbr = ft_count(str);
	dest = malloc(sizeof(char *) * (nbr + 2));
	if (!dest)
		return (NULL);
	while (x <= nbr)
	{
			start = ft_substart(str, x);
			dest[x] = ft_substr(str, start, ft_sublen(str, start));
			x++;
	}
	dest[x] = NULL;
	ft_substart(str, -1);
	return (dest);
}