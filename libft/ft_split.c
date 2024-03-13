/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:16:22 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 14:03:08 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnchr(char const *s, const char c)
{
	int	x;
	int	stock;

	x = 0;
	stock = 0;
	while (s[x] == c && s[x] != '\0')
		x++;
	if (s[x] == '\0')
		return (0);
	while (s[x] != '\0')
	{
		if (s[x] == c && s[x + 1] != c && s[x + 1] != '\0')
			stock++;
		x++;
	}
	return (stock + 1);
}

static int	ft_substart(const char *s, const char c, int x)
{
	int	i;
	int	check;

	i = 0;
	if (x == 0)
	{
		while (s[i] == c)
			i++;
		if (i > 0)
			return (i);
		else
			return (0);
	}
	check = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			check++;
		i++;
		if (s[i - 1] == c && check == x)
			return (i);
	}
	return (i);
}

static int	ft_sublen(const char *s, const char c, int start)
{
	int	x;

	x = 0;
	while (s[start] != c && s[start] != '\0')
	{
		start++;
		x++;
	}
	return (x + 1);
}

static void	ft_free_all(char **dest, int x)
{
	while (x >= 0)
	{
		free(dest[x]);
		x--;
	}
	free(dest);
	return ;
}

char	**ft_split(char const *s, char c)
{
	int		nbr_m;
	int		x;
	int		start;
	char	**dest;

	if (!(s))
		return (0);
	nbr_m = ft_strnchr(s, c);
	dest = ft_calloc((nbr_m + 1), sizeof(char *));
	if (!(dest))
		return (0);
	x = 0;
	while (x < nbr_m)
	{
		start = ft_substart(s, c, x);
		dest[x] = ft_substr(s, start, (ft_sublen(s, c, start) - 1));
		if (!(dest[x]))
		{
			ft_free_all(dest, x);
			return (0);
		}
		x++;
	}
	return (dest);
}
