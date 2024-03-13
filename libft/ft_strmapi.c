/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:37:12 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 16:24:41 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		x;
	char	*dest;

	if (!(f))
		return (0);
	if (!(s))
		return (0);
	x = 0;
	dest = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!(dest))
		return (0);
	while (s[x] != '\0')
	{
		dest[x] = f(x, s[x]);
		x++;
	}
	return (dest);
}
