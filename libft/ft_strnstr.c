/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:49:17 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 14:18:16 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	if (!big && len == 0)
		return (0);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[x] != '\0' && x < len)
	{
		while (big[x] == little[y] && big[x] != '\0'
			&& little[y] != '\0' && x < len)
		{
			x++;
			y++;
		}
		if (little[y] == '\0')
			return ((char *)big + (x - y));
		x = x - y;
		y = 0;
		x++;
	}
	return (0);
}
