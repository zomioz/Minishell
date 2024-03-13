/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:02:25 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 14:16:27 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(char *str, size_t n)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0' && x < n)
		x++;
	return (x);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	cpy;

	if (!dst && size == 0)
		return (0);
	len = ft_nlen(dst, size);
	if (len == size)
		return (len + ft_strlen(src));
	cpy = ft_strlcpy(dst + len, src, size - len);
	return (len + cpy);
}
