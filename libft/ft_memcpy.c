/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:13:26 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 14:04:35 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*st_src;
	unsigned char	*st_dest;

	if (!(src) && !(dest))
		return (0);
	x = 0;
	st_src = (unsigned char *)src;
	st_dest = (unsigned char *)dest;
	while (x < n)
	{
		st_dest[x] = st_src[x];
		x++;
	}
	return (dest);
}
