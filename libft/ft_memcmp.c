/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:18:42 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/01 16:08:03 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*s1_a;
	unsigned char	*s2_b;

	s1_a = (unsigned char *)s1;
	s2_b = (unsigned char *)s2;
	x = 0;
	if (n <= 0)
		return (0);
	while (s1_a[x] == s2_b[x] && x < (n - 1))
		x++;
	return (((unsigned char)s1_a[x]) - ((unsigned char)s2_b[x]));
}
