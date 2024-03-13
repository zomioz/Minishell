/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:44:43 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/03 17:58:29 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*stock;
	size_t			x;
	unsigned char	c2;

	c2 = c;
	x = 0;
	stock = (unsigned char *)s;
	while (x < n)
	{
		if (stock[x] == c2)
			return ((unsigned char *)s + x);
		x++;
	}
	return (0);
}
