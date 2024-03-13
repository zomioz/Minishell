/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:42:40 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/04 17:06:43 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_t;
	size_t	x;

	x = ft_strlen(s) + 1;
	s_t = ft_calloc(sizeof(char), x);
	if (s_t)
		ft_memcpy(s_t, s, x);
	return (s_t);
}
