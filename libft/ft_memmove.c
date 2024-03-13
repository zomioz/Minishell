/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:45:08 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/03 17:14:58 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_t;
	unsigned char	*src_t;

	dest_t = (unsigned char *)dest;
	src_t = (unsigned char *)src;
	if (src > dest)
		ft_memcpy(dest, src, n);
	else if (dest > src)
		while (n--)
			dest_t[n] = src_t[n];
	return (dest_t);
}
