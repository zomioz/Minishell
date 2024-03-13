/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:48:58 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/08 13:04:59 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			x;
	unsigned char	*stock;

	x = 0;
	stock = (unsigned char *)s;
	while (x < n)
	{
		stock[x] = 0;
		x++;
	}
}
