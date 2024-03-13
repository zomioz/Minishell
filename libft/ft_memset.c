/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:56:01 by pirulenc          #+#    #+#             */
/*   Updated: 2023/10/31 18:36:37 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*stock;

	stock = (unsigned char *)s;
	x = 0;
	while (x < n)
	{
		stock[x] = c;
		x++;
	}
	return (s);
}
