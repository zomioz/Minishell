/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:33:09 by pirulenc          #+#    #+#             */
/*   Updated: 2023/11/09 12:23:14 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((long long)nmemb < 0 || (long long)size < 0)
		return (0);
	ptr = malloc(nmemb * size);
	if (!(ptr))
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
