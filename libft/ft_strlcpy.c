/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:15:25 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/01 18:58:43 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	if (size != 0)
	{
		while (x < (size - 1) && src[x] != '\0')
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	while (src[x] != '\0')
		x++;
	return (x);
}
