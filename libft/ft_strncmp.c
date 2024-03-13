/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:14:28 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/01 15:37:04 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n <= 0)
		return (0);
	while (s1[x] != 0 && s2[x] != 0 && s1[x] == s2[x] && x < (n - 1))
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
