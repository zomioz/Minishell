/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:56:34 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 12:12:06 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	x;
	size_t	y;

	if (!(s1))
		return (0);
	x = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dest = malloc(x * sizeof(char));
	if (!(dest))
		return (0);
	x = 0;
	y = 0;
	while (s1[y] != '\0')
		dest[x++] = s1[y++];
	y = 0;
	while (s2[y] != '\0')
		dest[x++] = s2[y++];
	dest[x] = '\0';
	return (dest);
}
