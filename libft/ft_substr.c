/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:17:30 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 12:10:48 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	len_m;
	size_t	y;

	if (!(s))
		return (0);
	y = 0;
	len_m = ft_strlen(s) - start;
	if (len_m >= len)
		len_m = len;
	if (start > ft_strlen(s))
		len_m = 0;
	dest = malloc((len_m + 1) * sizeof(char));
	if (!(dest))
		return (0);
	ft_bzero(dest, len_m + 1);
	while (y < len_m)
		dest[y++] = s[start++];
	return (dest);
}
