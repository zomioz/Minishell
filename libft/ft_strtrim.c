/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:09:58 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/10 13:41:32 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_found_trim(char const c, char const *set)
{
	int	x;

	x = 0;
	while (set[x] != '\0')
	{
		if (set[x] == c)
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len_s1;
	size_t	x;

	if (s1 == 0)
		return (0);
	x = 0;
	len_s1 = ft_strlen(s1) - 1;
	while (len_s1 > 0 && ft_found_trim(s1[len_s1], set) == 1)
		len_s1--;
	if (len_s1 == 0)
	{
		dest = ft_calloc (1, sizeof(char));
		return (dest);
	}
	while (s1[x] != '\0' && ft_found_trim(s1[x], set) == 1)
		x++;
	dest = ft_substr(s1, x, (len_s1 - x) + 1);
	return (dest);
}
