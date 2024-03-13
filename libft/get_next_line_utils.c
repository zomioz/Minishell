/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:05:41 by pirulenc          #+#    #+#             */
/*   Updated: 2023/12/17 10:32:44 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dest;
	size_t	x;
	size_t	y;

	if (s1)
		x = (ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		x = ft_strlen(s2) + 1;
	dest = ft_calloc(sizeof(char), x);
	if (!(dest))
		return (0);
	y = 0;
	x = 0;
	if (s1)
	{
		while (s1[y] != '\0' && s1)
			dest[x++] = s1[y++];
	}
	y = 0;
	while (s2[y] != '\0')
		dest[x++] = s2[y++];
	if (s1)
		free(s1);
	return (dest);
}
